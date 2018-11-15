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
  setForward(255);
  delay(5000);
  setBackward(255);
  delay(5000);
  setClockwise(255);
  delay(5000);
  setAnticlockwise(255);
  delay(5000);
}
