# HighAltBalloon_Due
Project to make a high-altitude balloon using an Arduino Due, which uses SAM3X boards and a [Si5351 Model B] (https://www.digikey.com/product-detail/en/silicon-labs/SI5351B-B-GM/336-2401-ND/3679849) radio transmitter. 
The radio transmitter is the Model B version of the [Model A version] (https://www.adafruit.com/product/2045) made easier to hack becayse of Adafruit's awesome schematics.

A lot of the code was taken from [this] (https://www.tracksoar.com/source/) open-source project for high-altitude balloons (made for Arduino Unos (which is AVR)) and a different radio transmitter.

Most of the modified files are for AFSK (Audio frequency shift keying) using the Arduino Due's DAC.
The modified or newly added files are listed below.
* Tracksoar_Due.cpp
* AFSK Files
  * afsk.cpp
  * afsk_due.cpp
  * afsk_due.h
* Si5351 Radio Files
  * radio_si5351.cpp
  * radio_si5351.h
