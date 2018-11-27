/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

// ** Preamble ** //
//#include "firmware.h"

void setup () {
    pinMode(6, OUTPUT);
 
    //begin serial communication
    Serial.begin(9600);
}

void loop() {
  
  digitalWrite(6, HIGH);
  Serial.println("On!");
  delay(1000);
  digitalWrite(6, LOW);
  Serial.println("Off!");
  delay(1000);
  
}
