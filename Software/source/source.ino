/*
 * source.ino
 *
 * Created: 7/11/2018
 * Author: T. Crossley
 *
 */

// ** Preamble ** //
#include "mines.h"
#include "indicate.h"
#include "movement.h"

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
