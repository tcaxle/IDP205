/*
 * test_getCoord.ino
 *
 * Created: 26/11/2018
 * Author: L. Anderson
 *
 */

// ** Preamble ** //
// PRESERVE THIS ORDER FOR ANYTHING TO WORK
#include "libraries.h" // 0
#include "classes.h" // 1
#include "firmware.h" // 2
#include "indicate.h" // 3
#include "orientation.h" // 4
#include "movement.h" // 5

void loop() {
  
    //getCoord test
    if(runCounter == 0){
        compassOffset = initialiseOrientation();
        runCounter += 1;
    }
    coord currentCoord = getCoords(getDirection());
    Serial.print("Current X Coordinate: ");
    Serial.println(currentCoord.x);
    Serial.print("Current Y Coordinate: ");
    Serial.println(currentCoord.y);
    delay(5000);

}
