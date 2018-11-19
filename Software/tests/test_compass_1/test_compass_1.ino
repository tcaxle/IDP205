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
  float currentHeading = robotCompass.getHeading();
  int currentDirection = getDirection(robotCompass);
  Serial.print("Compass Heading: ");
  Serial.println(currentHeading);
  Serial.print("Cartesian Direction: ");
  Serial.println(currentDirection);
  delay(500);
}
