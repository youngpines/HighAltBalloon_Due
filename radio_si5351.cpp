#include "si5351.h"

//Make PLLB_FREQ a multiple of desired carrier frequency (this case, 144.330 MHz)
#define PLLB_FREQ    86598000000ULL

void radio_setup(Si5351 *radio_object) {
  radio_object->init(SI5351_CRYSTAL_LOAD_8PF, 26000000UL, 0UL);
  radio_object->output_enable(SI5351_CLK0, 0); //disable right now
  radio_object->set_clock_pwr(SI5351_CLK0, 1);
  //si5351.drive_strength(SI5351_CLK0, SI5351_DRIVE_8MA); //default is lowest

  // Set VCXO osc to defined value, 30 ppm pull
  radio_object->set_vcxo(PLLB_FREQ, 30);

  // Set CLK0 to be locked to VCXO
  radio_object->set_ms_source(SI5351_CLK0, SI5351_PLLB);
  
  // Set CLK0 to output 144.330 MHz
  radio_object->set_freq(14433000000ULL, SI5351_CLK0);

  //Status results come up in Serial Monitor
  radio_object->update_status();
}

void radio_turn_on(Si5351 *radio_object){
  radio_object->output_enable(SI5351_CLK0, 1);
}

void radio_turn_off(Si5351 *radio_object){
  radio_object->output_enable(SI5351_CLK0, 0);
}

