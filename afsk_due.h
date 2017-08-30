//Following format of other .h files but for Arduino Due

#ifdef ARDUINO_SAM_DUE

#ifndef __AFSK_DUE_H__
#define __AFSK_DUE_H__

#include <stdint.h>
#include <Wire.h>
//#include <avr/pgmspace.h> //for sinwavetable table
#include "config.h"

#define AFSK_ISR TC3_Handler()

//Exported constants
extern const uint32_t MODEM_CLOCK_RATE;
extern const uint16_t TABLE_SIZE;

//Exported variables
extern const uint16_t afsk_sine_table[];

//inline functions
inline uint16_t afsk_read_sample(int phase) {
  return afsk_sine_table[phase];
}

inline void afsk_output_sample(uint16_t s) {
  dacc_write_conversion_data(DACC_INTERFACE, s);
}

inline void afsk_clear_interrupt_flag()
{
  // atmegas don't need this as opposed to pic32s.
}

//Exported functions
void afsk_setup();
void afsk_send(const uint8_t * buffer, int len);
void afsk_start();
bool afsk_flush();
void afsk_isr(); //TODO where is this??
void afsk_timer_setup(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t freq);
void afsk_timer_start(Tc *tc, uint32_t channel);
void afsk_timer_stop(Tc *tc, uint32_t channel);

#endif
#endif //SAM board
