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
        Serial.println("Ready!");
        delay(8000);
        compassOffset = initialiseOrientation();
        arena = initialiseArenaBoundaries();
        pathGo(target);
        
        runCounter += 1;
    }
}
