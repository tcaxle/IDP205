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
  redLed.init();
  
  redLed.set(1);
  delay(500);
  redLed.set(0);
  delay(500);
}
