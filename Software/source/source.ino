/*
 * source.h
 *
 *  Created on: 8 Nov 2018
 *      Author: tom
 *
 *  Test file
 */

#include "firmware.h"

void setup () {
  
  
}

void loop() {
  
  // declare an LED on pin 53, default off
  led redLed;
  redLed.pin = 53;
  redLed.default_status = 0;
  redLed.init();
  
  redLed.turnOn();
  delay(1000);
  redLed.turnOff();
  delay(1000);
}
