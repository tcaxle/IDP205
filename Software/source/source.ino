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
    // Initialise compass, arena boundaries and safe zone boundaries
    compassOffsett = initialiseOrientation();
    arena = initialiseArenaBoundaries();
    dangerZone = rectangle(30, arena.x1 - 30, 30, arena.y1 - 30);

    
}

    /* Tom's random code, preserved for posterity
    float angle = random(-179, 180);
    Serial.println(angle);
    faceAngle(angle);
    delay(1000);
    */
