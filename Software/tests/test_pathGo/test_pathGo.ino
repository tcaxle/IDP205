/*
 * test_pathGo.ino
 *
 * Created: 26/11/2018
 * Author: L. Anderson
 *
 */

// PRESERVE THIS ORDER FOR ANYTHING TO WORK
#include "libraries.h" // 0
#include "classes.h" // 1
#include "firmware.h" // 2
#include "indicate.h" // 3
#include "orientation.h" // 4
#include "movement.h" // 5

// Initialise sigle destination co-ordinate for pathGo test
coord target(50, 50);

void loop() {
    //pathGo test
    if (runCounter == 0){
        compassOffset = initialiseOrientation();
        pathGo(target);
        runCounter += 1;
    }
}
