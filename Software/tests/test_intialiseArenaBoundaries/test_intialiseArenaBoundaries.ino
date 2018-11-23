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
    if (runCounter == 0){
        compassOffset = initialiseOrientation();
        arenaVector = initialiseArenaBoundaries();
        arenaX = arenaVector.front();
        arenaY = arenaVector.back();
        Serial.println(arenaX);
        Serial.println(arenaY);
        runCounter += 1;
    }
}
