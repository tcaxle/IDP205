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


void loop() {
  float currentHeading = robotCompass.heading();
  Serial.print("Compass Heading: ");
  Serial.println(currentHeading);
}
