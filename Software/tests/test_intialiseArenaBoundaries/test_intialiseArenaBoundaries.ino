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
