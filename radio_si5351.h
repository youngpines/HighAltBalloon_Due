#ifndef __RADIO_SI5351_H__
#define __RADIO_SI5351_H__

#include "si5351.h"

void radio_setup(Si5351 *radio_object);
void radio_turn_on(Si5351 *radio_object);
void radio_turn_off(Si5351 *radio_object);

#endif
