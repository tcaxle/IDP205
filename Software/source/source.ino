#include <Wire.h>

/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

#include "firmware.h"
#include "Adafruit_MotorShield.h"

void setup () {
  
  test.pin = 53;
  test.default_status = 0;
  test.init();

}

void loop() {
  
  
  test.turnOn();
  delay(100);
  test.turnOff();
  delay(100);
  
}
