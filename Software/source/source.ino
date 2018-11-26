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
    /* Tom's random code, preserved for posterity
    float angle = random(-179, 180);
    Serial.println(angle);
    faceAngle(angle);
    delay(1000);
    */

    
    
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
}
