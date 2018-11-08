/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

#include "firmware.h"

void setup () {
  Serial.begin(115200);
  Serial.print("Hello");
  
  LED.pin = 53;
  LED.default_status = 0;
  LED.init();

}

void loop() {
  
  
  LED.set(1);
  delay(100);
  LED.set(0);
  delay(100);
  
}
