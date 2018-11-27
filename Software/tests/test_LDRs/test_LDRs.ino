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

void loop () {
  Serial.print(LDR00.voltage());
  Serial.print(", ");
  Serial.print(LDR01.voltage());
  Serial.print(", ");
  Serial.print(LDR02.voltage());
  Serial.print(", ");
  Serial.print(LDR03.voltage());
  Serial.print(", ");
  Serial.print(LDR07.voltage());
  Serial.print(", ");
  Serial.print(LDR08.voltage());
  Serial.print(", ");
  Serial.print(LDR09.voltage());
  Serial.print(", ");
  Serial.print(LDR10.voltage());
  Serial.print(", ");
  Serial.println(LDR11.voltage());
}

