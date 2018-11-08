/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

#include "classes.h"
#include "firmware.h"

void setup () {
  
  
}

void loop() {
  
  // declare an LED on pin 53, default off
  digital_output LED;
  LED.pin = 53;
  LED.default_status = 0;
  LED.init();
  
  LED.set(1);
  delay(1000);
  LED.set(0);
  delay(1000);
}
