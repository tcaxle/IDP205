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
#include "movement.h"

void loop() {
  leftMotor.setSpeed(60);
  rightMotor.setSpeed(60);
  leftMotor.setForward();
  rightMotor.setBackward();

  /*//Flux tests
  Serial.print(compass.getXFlux());
  Serial.print(", ");
  Serial.println(Mcompass.getYFlux());
  Serial.print(compass.getCorrectedXFlux());
  Serial.print(", ");
  Serial.println(compass.getCorrectedYFlux());
  Serial.println();
  */
  
  //Angle tests
  float currentHeading = compass.getHeading();
  int currentDirection = getDirection();
  Serial.print("Compass Reading: ");
  Serial.println(currentHeading);
  Serial.print("Cartesian Direction: ");
  Serial.println(currentDirection);
  Serial.println();
  
  delay(1000);
}
