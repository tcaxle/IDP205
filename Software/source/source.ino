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
#include "motorControl.h" // 5
#include "facing.h" // 6
#include "setup.h" // 7
#include "locate.h" // 8
#include "pathGen.h" // 9
#include "movement.h" // 10

void loop() {

    
    // Initialise compass, arena boundaries and safe zone boundaries
    compassOffset = initialiseOrientation();
    arena = initialiseArenaBoundaries();
    dangerZone = rectangle(30, arena.x1 - 30, 30, arena.y1 - 30);

    // Get robot's current position
    position = getCoords();
    homeCoord = position;


    // While the robot has yet to reach the end of the mined area
    while(dangerZone.y1 - position.y >= ROBOT_WIDTH/2){
        path = generateSearchPath();
        for(int coordIndex = 0; coordIndex < path.size(); coordIndex += 1){
            pathFollow(path);
        }
        position = getCoords();
        if (dangerZone.y1 - position.y >= ROBOT_WIDTH/2){
            faceAngle(90);
            moveFwd(ROBOT_WIDTH);
        }
        if (xOrientation == 0){
            xOrientation = 180;
        }
        else{
            xOrientation = 0;
        }
    }
    path = generateHomePath();
    for(int coordIndex = 0; coordIndex < path.size(); coordIndex += 1){
            pathFollow(path);
    }
    

}

    /* Tom's random code, preserved for posterity
    float angle = random(-179, 180);
    Serial.println(angle);
    faceAngle(angle);
    delay(1000);
    */

    
    /*
    int i = 0;
    LDRreading = LDRreading / 5.0;
    Serial.println(LDRreading);
    if (LDRreading >= LDRaverage + 20) { // SAFE
      red.set(0);
      yellow.set(1);
      green.set(0);
      setStop();
      setBwd();
      delay(10);
      setStop();
      delay(3000);
    } else if (LDRreading > LDRaverage + 5 && LDRreading < LDRaverage + 20) { // DANGER
      red.set(1);
      yellow.set(0);
      green.set(0);
      setStop();
      setBwd();
      delay(10);
      setStop();
      delay(3000);
    } else { // NO MINE
      red.set(0);
      setFwd();
    }
    */

    /*
    delay(1000);
    setStop();
    mineGrab();
    setClockwise();
    delay(2500);
    setStop();
    mineDrop();
    setBwd();
    delay(1000);
    setAnticlockwise();
    delay(2500);
    */
    
