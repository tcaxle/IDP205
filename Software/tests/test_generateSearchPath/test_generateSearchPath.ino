/*
 * test_generateSearchPath.ino
 *
 * Created: 23/11/2018
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

void loop() {
    if (runCounter == 0) {
    compassOffset = initialiseOrientation();
    arena = initialiseArenaBoundaries();
    dangerZone = rectangle(30, arena.x1 - 30, 30, arena.y1 - 30);
    path = generateSearchPath();
    runCounter++;
    }
}
