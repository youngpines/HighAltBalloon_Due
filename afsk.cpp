/* trackuino copyright (C) 2010  EA5HAV Javi
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/* Credit to:
 *
 * Michael Smith for his Example of Audio generation with two timers and PWM:
 * http://www.arduino.cc/playground/Code/PCMAudio
 *
 * Ken Shirriff for his Great article on PWM:
 * http://arcfn.com/2009/07/secrets-of-arduino-pwm.html 
 *
 * The large group of people who created the free AVR tools.
 * Documentation on interrupts:
 * http://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html
 */

#include "config.h"
#include "afsk_avr.h"
#include "afsk_pic32.h"
#include "afsk_due.h"
#include "pin.h"
#include "radio_si5351.h"
#if (ARDUINO + 1) >= 100
#  include <Arduino.h>
#else
#  include <WProgram.h>
#endif
#include <stdint.h>

// Module consts
#define DEBUG_AFSK1
//PLAYBACK_RATE was the same as the number of datapoints per sine wave (ie, the var samples)
//so, PLAYBACK_RATE = SAMPLES_PER_BAUD * BAUD_RATE
// The actual baudrate after rounding errors will be:
// PLAYBACK_RATE / (integer_part_of((PLAYBACK_RATE * 256) / BAUD_RATE) / 256)
//remember Due's DAC is 12-bit
static const uint16_t BAUD_RATE       = 1200;
extern const uint32_t SAMPLES_PER_BAUD = 20;  // Fixed point 12.20 for consistency
static const uint32_t PHASE_DELTA_1200 = (TABLE_SIZE << 20) / SAMPLES_PER_BAUD; // Fixed point 12.20
static const uint32_t PHASE_DELTA_2200 = ((2200 << 6 / 1200) * PHASE_DELTA_1200) >> 6; //also 12.20
static const uint8_t SAMPLE_FIFO_SIZE = 32;


// Module globals
volatile static uint8_t current_byte;
volatile static uint16_t current_sample_in_baud;          // 1 bit = SAMPLES_PER_BAUD samples
volatile static bool go = false;                         // Modem is on
volatile static uint32_t phase_delta;                    // 1200/2200 for standard AX.25
volatile static uint32_t phase;                          // Fixed point 12.20 for consistency
volatile static uint32_t packet_pos;                     // Next bit to be sent out
volatile static uint16_t sample_fifo[SAMPLE_FIFO_SIZE];   // queue of samples
volatile static uint8_t sample_fifo_head = 0;            // empty when head == tail
volatile static uint8_t sample_fifo_tail = 0;
volatile extern uint32_t sample_overruns = 0;

volatile bool state = LOW;
volatile extern int counter = 0;

/*
// The radio (class defined in config.h)
static RadioHx1 radio;
*/
//The radio, si5351 model B
static Si5351 si5351;
Si5351 *si5351_object = &si5351;


volatile static unsigned int afsk_packet_size = 0;
volatile static const uint8_t *afsk_packet;


// Module functions

inline static bool afsk_is_fifo_full()
{
  return (((sample_fifo_head + 1) % SAMPLE_FIFO_SIZE) == sample_fifo_tail);
}

inline static bool afsk_is_fifo_full_safe()
{
  noInterrupts();
  boolean b = afsk_is_fifo_full();
  interrupts();
  return b;
}

inline static bool afsk_is_fifo_empty()
{
  return (sample_fifo_head == sample_fifo_tail);
}

inline static bool afsk_is_fifo_empty_safe()
{
  noInterrupts();
  bool b = afsk_is_fifo_empty();
  interrupts();
  return b;
}

inline static void afsk_fifo_in(uint16_t s)
{
  sample_fifo[sample_fifo_head] = s;
  sample_fifo_head = (sample_fifo_head + 1) % SAMPLE_FIFO_SIZE;
}
 
inline static void afsk_fifo_in_safe(uint16_t s)
{
  noInterrupts();
  afsk_fifo_in(s);
  interrupts();
}
  
inline static uint16_t afsk_fifo_out()
{
  uint16_t s = sample_fifo[sample_fifo_tail];
  sample_fifo_tail = (sample_fifo_tail + 1) % SAMPLE_FIFO_SIZE;
  return s;
}

inline static uint16_t afsk_fifo_out_safe()
{
  noInterrupts();
  uint16_t b = afsk_fifo_out();
  interrupts();
  return b;
}
  

// Exported functions

void afsk_setup()
{
  // Start radio
  radio_setup(si5351_object);

  //Cheat to enable DAC
  analogWrite(DAC0, 0);
}

void afsk_send(const uint8_t *buffer, int len)
{
  afsk_packet_size = len;
  afsk_packet = buffer;
}

void afsk_start()
{
  phase_delta = PHASE_DELTA_1200;
  phase = 0;
  packet_pos = 0;
  current_sample_in_baud = 0;
  go = true;

  // Prime the fifo
  afsk_flush();

  // Start timer (CPU-specific)
  afsk_timer_setup(TC1, 0, TC3_IRQn, 1200);

  // Key the radio
  //radio.ptt_on();
  radio_turn_on(si5351_object);
  
  // Start transmission
  afsk_timer_start(TC1, 0);
}

bool afsk_flush()
{
  while (! afsk_is_fifo_full_safe()) {
    // If done sending packet
    if (packet_pos == afsk_packet_size) {
      go = false;         // End of transmission
    }
    if (go == false) {
      if (afsk_is_fifo_empty_safe()) {
        afsk_timer_stop(TC1, 0);  // Disable modem
        radio_turn_off(si5351_object);    // Release PTT & disable output
        return false;       // Done
      } else {
        return true;
      }
    }

    // If sent SAMPLES_PER_BAUD already, go to the next bit
    if (current_sample_in_baud < (1)) {    // Load up next bit
      if ((packet_pos & 7) == 0) {         // Load up next byte
        current_byte = afsk_packet[packet_pos >> 3];
      } else {
        current_byte = current_byte / 2;  // ">>1" forces int conversion
      }
      if ((current_byte & 1) == 0) {
        // Toggle tone (1200 <> 2200)
        phase_delta ^= (PHASE_DELTA_1200 ^ PHASE_DELTA_2200);
      }
    }
      
    phase += phase_delta;
    uint16_t s = afsk_read_sample((phase >> 20) & (TABLE_SIZE - 1));

#ifdef DEBUG_AFSK
    Serial.print((uint16_t)s);
    Serial.print('/');
#endif
  
#if PRE_EMPHASIS2 == 1
    if (phase_delta == PHASE_DELTA_1200)
      s = s / 2 + 64;
#endif

#ifdef DEBUG_AFSK
    Serial.print((uint16_t)s);
    Serial.print(' ');
#endif
    afsk_fifo_in_safe(s);
  
    current_sample_in_baud += (1);
    if (current_sample_in_baud >= SAMPLES_PER_BAUD) {
#ifdef DEBUG_AFSK
      Serial.println();
#endif
      packet_pos++;
      current_sample_in_baud = 0;
    }
  }
  
  return true;  // still working
}

// This is called at PLAYBACK_RATE Hz to load the next sample.
void TC3_Handler()
{
  TC_GetStatus(TC1, 0); //Initialize Timer Counter 1
  digitalWrite(A0, !state);
  counter++;
  state = !state;
  if (afsk_is_fifo_empty()) {
    if (go) {
      sample_overruns++;
    }
  } else {
    afsk_output_sample(afsk_fifo_out());
  }
  afsk_clear_interrupt_flag();
}

#ifdef DEBUG_MODEM
void afsk_debug()
{
  Serial.print("fifo overruns=");
  Serial.println(sample_overruns);

  sample_overruns = 0;
}
#endif

