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


void loop() {
    /*// Test for vector output
    if (runCounter == 0){
        compassOffset = initialiseOrientation();
        arenaVector = initialiseArenaBoundaries();
        arenaX = arenaVector.front();
        arenaY = arenaVector.back();
        Serial.println(arenaX);
        Serial.println(arenaY);
        runCounter += 1;
    }*/
    
    // Test for rectangle output
    if (runCounter == 0){
        Serial.println("Ready!");
        delay(5000);
        compassOffset = initialiseOrientation();
        arena = initialiseArenaBoundaries();
        Serial.print("Arena lower left corner: (");
        Serial.print(arena.c.x);
        Serial.print(", ");
        Serial.print(arena.c.y);
        Serial.println(")");
        Serial.print("Arena upper left corner: (");
        Serial.print(arena.a.x);
        Serial.print(", ");
        Serial.print(arena.a.y);
        Serial.println(")");
        Serial.print("Arena upper right corner: (");
        Serial.print(arena.b.x);
        Serial.print(", ");
        Serial.print(arena.b.y);
        Serial.println(")");
        Serial.print("Arena lower right corner: (");
        Serial.print(arena.d.x);
        Serial.print(", ");
        Serial.print(arena.d.y);
        Serial.println(")");
        runCounter += 1;
    }
}
