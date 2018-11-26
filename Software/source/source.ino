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

    Serial.print(LDR00.voltage());
    Serial.print(", ");
    Serial.print(LDR01.voltage());
    Serial.print(", ");
    Serial.print(LDR02.voltage());
    Serial.print(", ");
    Serial.print(LDR03.voltage());
    Serial.print(", ");
    Serial.print(LDR04.voltage());
    Serial.print(", ");

    Serial.print(LDR08.voltage());
    Serial.print(", ");
    Serial.print(LDR09.voltage());
    Serial.print(", ");
    Serial.print(LDR10.voltage());
    Serial.print(", ");
    Serial.print(LDR11.voltage());
    Serial.println();
    delay(100);
}
