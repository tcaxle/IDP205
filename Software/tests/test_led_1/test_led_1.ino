/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

// ** Preamble ** //
#include "firmware.h"

void setup () {
  
  test.pin = 53;
  test.init();

}

void loop() {
  
  
  test.set(0);
  delay(100);
  test.set(1);
  delay(100);
  
}
