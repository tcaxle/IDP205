/*
 * Test_1.cpp
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 */

#include <Arduino.h>

void setup() {
    pinMode(53, OUTPUT);
}

void loop() {
    digitalWrite(53, 0);
    delay(1000);
    digitalWrite(53, 1);
    delay(1000);
}




