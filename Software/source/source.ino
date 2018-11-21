/*
 * source.ino
 *
 * Created: 7/11/2018
 * Author: T. Crossley
 *
 */

// ** Preamble ** //
// PRESERVE THIS ORDER FOR ANYTHING TO WORK
#include "libraries.h" // 0
#include "classes.h" // 1
#include "firmware.h" // 2
#include "mines.h" // 3
#include "indicate.h" // 4
#include "orientation.h" // 5
#include "movement.h" // 6

void loop() {
    /* Path follower test
    // On first run
    if (runCounter == 0){
        compassOffset = initialiseOrientation();
        arenaVector = initialiseArenaBoundaries();
        arenaX = arenaVector.front();
        arenaY = arenaVector.back();
        // Initialise circular path co-ordinates
        coord point1(50, 50);
        coord point2(50, arenaY-50);
        coord point3(arenaX-50, arenaY-50);
        coord point4(arenaX-50, arenaY-50);
    }
    // Populate path
    path.push_back(point4);
    path.push_back(point3);
    path.push_back(point2);
    path.push_back(point1);
    // Follow path
    pathFollow(path);
    */

    compassOffset = initialiseOrientation();
    
    /* Tom's random code, preserved for posterity
    float angle = random(-179, 180);
    Serial.println(angle);
    faceAngle(angle);
    delay(1000);
    */
}
