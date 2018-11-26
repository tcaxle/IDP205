/*
 * test_moveFwd.ino
 *
 * Created: 26/11/2018
 * Author: L. Andersom
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
    //moveFwd test
    if (runCounter == 0){
        moveFwd(30);
        runCounter += 1;
    }
}
