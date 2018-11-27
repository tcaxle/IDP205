/*
 * test_pathGo.ino
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
#include "mines.h" // 3
#include "indicate.h" // 4
#include "motorControl.h" // 5
#include "facing.h" // 6
#include "setup.h" // 7
#include "locate.h" // 8
#include "pathGen.h" // 9
#include "movement.h" // 10


// Initialise sigle destination co-ordinate for pathGo test
coord target(100, 100);

void loop() {
    //pathGo test
    if (runCounter == 0){
        Serial.println("running");
        Serial.println("#1");
        compassOffset = compass.getHeading();
        Serial.println("#2");
        arena = initialiseArenaBoundaries();
        Serial.println("#3");
        pathGo(coord(50,50));
        Serial.println("#4");
        pathGo(coord(50, 100));
        Serial.println("#5");
        
        runCounter += 1;
    }
}
