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
#include "mines.h" // 4
#include "orientation.h" // 5
#include "movement.h" // 6

void loop() {
    if (runCounter == 0) {
    compassOffset = initialiseOrientation();
    arena = initialiseArenaBoundaries();
    dangerZone = rectangle(30, arena.x1 - 30, 30, arena.y1 - 30);
    path = generateSearchPath();
    pathSize = path.size();
    for(int coordCounter = 1; coordCounter < pathSize; coordCounter += 1){
      pathFollow(path);  
    }
    runCounter++;
    }
}
