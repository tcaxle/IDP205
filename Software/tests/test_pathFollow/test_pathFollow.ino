/*
* source.ino
*
* Created: 23/11/2018
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


// Initialise circular path co-ordinates
coord point1(50, 50);
coord point2(50, 100);
coord point3(50, 150);
coord point4(100, 150);
coord point5(150, 150);
coord point6(150, 100);
coord point7(150, 50);
coord point8(100, 50);

void loop() {
    /*// On first run
    if (runCounter == 0){
        compassOffset = initialiseOrientation();
        Serial.println("Ready!");
        delay(8000);
    }
    // Populate path
    Serial.print("Populating... ");
    path.push_back(point8);
    path.push_back(point7);
    path.push_back(point6);
    path.push_back(point5);
    path.push_back(point4);
    path.push_back(point3);
    path.push_back(point2);
    path.push_back(point1);
    Serial.println("Done!");
    Serial.println();
    // Follow path
    pathFollow(path);
    runCounter += 1;*/
}
