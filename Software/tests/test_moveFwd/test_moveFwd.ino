/*
 * test_moveFwd.ino
 *
 * Created: 26/11/2018
 * Author: L. Andersom
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
    // moveFwd test
    if (runCounter == 0){
        Serial.println(moveFwd(100));
        runCounter += 1;
    }
}
