/*
 * test_us_1.h
 *
 *  Created on: 8 Nov 2018
 *      Author: lewis
 *
 *  Tests motor class
 */

#include "libraries.h"
#include "classes.h"
#include "firmware.h"
void loop() {
    int xDist = xUltrasound.getTime();
    int yDist = yUltrasound.getTime();
    //Serial.print("X Measurement: ");
    Serial.println(xDist);
    //Serial.println("cm");
    //Serial.print("Y Measurement: ");
    //Serial.print(yDist);
    //Serial.println("cm");
    delay(100);
}
