/*
 * motorTest.h
 *
 *  Created on: 8 Nov 2018
 *      Author: lewis
 *
 *  Tests compass class
 */

#include "libraries.h"
#include "classes.h"
#include "firmware.h"
#include "orientation.h"

void loop() {
  leftMotor.setSpeed(60);
  rightMotor.setSpeed(60);
  leftMotor.setForward();
  rightMotor.setBackward();
  float currentHeading = robotCompass.getHeading();
  int currentDirection = getDirection(robotCompass);
  Serial.print("Compass Reading: ");
  Serial.println(currentHeading);
  Serial.print("Cartesian Direction: ");
  Serial.println(currentDirection);
  Serial.println();
  delay(1000);
}
