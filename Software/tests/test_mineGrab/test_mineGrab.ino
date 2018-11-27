/*
 * test_pathGo.ino
 *
 * Created: 26/11/2018
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
    if (runCounter == 0){
        if (!moveFwd(50)){
            Serial.println("Mine detected");
            delay(3000);
            vector<int> mineReadings = getMineReadings();
            int mostExtremeReading = 2;
            for (int readingCounter = 0; readingCounter < mineReadings.size(); readingCounter += 1){
                Serial.println(mineReadings[readingCounter]);
                if (mineReadings[readingCounter] == 1){
                    mostExtremeReading = 1;
                }
            }
            if (mostExtremeReading == 1){
                Serial.println("Safe mine");
            }
            else if (mostExtremeReading == 2){
                Serial.println("Dangerous mine");
            }   
        }
        runCounter += 1;
      }
    }
