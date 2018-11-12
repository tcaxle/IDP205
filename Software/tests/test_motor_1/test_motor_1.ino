/*
 * motorTest.h
 *
 *  Created on: 8 Nov 2018
 *      Author: lewis
 *
 *  Tests motor class
 */

#include "firmware.h"

Adafruit_MotorShield motorShield = Adafruit_MotorShield();

void setup () {
    motorShield.begin();
}

void loop() {
  // initialise DC motor at motor shield port M1
  motor leftMotor;
  leftMotor.assignedMotorShield = motorShield;
  leftMotor.port = 1;
  leftMotor.init();
}
