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
    // On first run
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
    runCounter += 1;
}
