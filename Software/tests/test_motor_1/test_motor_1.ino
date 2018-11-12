/*
 * motorTest.h
 *
 *  Created on: 8 Nov 2018
 *      Author: lewis
 *
 *  Tests motor class
 */

#include "firmware.h"

void loop() {
  // initialise DC motor at motor shield port M1
  leftMotor.setForward();
  leftMotor.setSpeed(30);
  delay(4000);
  leftMotor.setSpeed(60);
  delay(4000);
  leftMotor.setSpeed(120);
  delay(4000);
  leftMotor.setSpeed(240);
  delay(4000);
  leftMotor.emergencyStop();
  delay(4000);
  leftMotor.setSpeed(240);
  leftMotor.setBackward();
  delay(4000);
  leftMotor.setSpeed(0);
}
