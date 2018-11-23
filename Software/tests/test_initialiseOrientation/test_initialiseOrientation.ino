/*
* source.ino
*
* Created: 23/11/2018
* Author: L. Anderson
*
*/

#include "libraries.h"
#include "classes.h"
#include "firmware.h"
#include "indicate.h"
#include "orientation.h"
#include "movement.h"

void loop() {
    //initialiseOrientation test
    if (runCounter == 0){
        compassOffset = initialiseOrientation();
        runCounter += 1;
    }
    setClockwise(60);
    Serial.println(compassOffset);
    Serial.println(compass.getHeading());
    Serial.println(getDirection());
    Serial.println();
    delay(500);
}
