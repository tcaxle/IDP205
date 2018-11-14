/*
 * source.ino
 *
 * Created: 7/11/2018
 * Author: T. Crossley
 *
 */

// ** Preamble ** //
// PRESERVE THIS ORDER FOR ANYTHING TO WORK
#include "libraries.h" // 0
#include "classes.h" // 1
#include "firmware.h" // 2
#include "mines.h" // 3
#include "indicate.h" // 4
#include "movement.h" // 5

void loop() {
  // initialise DC motor at motor shield port M1
  leftMotor.setForward();
  leftMotor.setSpeed(255);
  delay(1000);
  leftMotor.emergencyStop();
  leftMotor.setBackward();
  leftMotor.setSpeed(255);
  delay(1000);
  leftMotor.emergencyStop();
}
