/*
 * motorTest.h
 *
 *  Created on: 8 Nov 2018
 *      Author: lewis
 *
 *  Tests motor class
 */

#include "firmware.h"

void setup () {
  
}

void loop() {
  
  // initialise DC motor at motor shield port M1
  motor leftMotor;
  leftMotor.port = 1;
  leftMotor.init()
}
