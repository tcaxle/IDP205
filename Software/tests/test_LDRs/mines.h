/*
 * mines.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * Contains functions for interaction with mines
 */

// ** Preamble ** //

// **** PUBLIC **** //

// ** Servo Stuff ** //

void servoMove(int endPos, int startPos = arm.read(), int stepDelay = 50, int stepDegree = 1) {
  int currentPos;
  if (startPos < endPos) {
    for (currentPos = startPos; currentPos <= endPos; currentPos += stepDegree) {
      arm.write(currentPos);
      delay(15);
    }
  } else {
    for (currentPos = startPos; currentPos >= endPos; currentPos -= stepDegree) {
      arm.write(currentPos);
      delay(15);
    }
  }
}

// ** Variables ** //
bool isHoldingMine = false; // A flag to indicate whether or not the robot is holding a mine

// ** Mine Interaction ** //
void calibrateLDRs() {
  // ONLY CALL WHEN ALL LDRS OVER BLACK
  LDR00.calibrate();
  LDR01.calibrate();
  LDR02.calibrate();
  LDR03.calibrate();
  LDR07.calibrate();

  LDR08.calibrate();
  LDR09.calibrate();
  LDR10.calibrate();
  LDR11.calibrate();
}

int singleDetectMine(ldr target) {
  // 0 for NONE
  // 1 for SAFE
  // 2 for DANGER
  float reading = target.voltage();
  float datum = target.datum;
  float THDanger = 60;
  float THSafe = 150;
  if (reading >= datum + THSafe) { // SAFE
    //Serial.println("Safe");
    return(1); // SAFE
  }
  if (reading > datum + THDanger && reading < datum + THSafe) {
    //Serial.println("Danger");
    return(2); // DANGER
  } else {
    //Serial.println("Nowt");
    return(0);
  }
}

vector<int> getMineReadings() {
  vector<int> output;
  output.push_back(singleDetectMine(LDR00));
  output.push_back(singleDetectMine(LDR01));
  output.push_back(singleDetectMine(LDR02));
  output.push_back(singleDetectMine(LDR03));
  output.push_back(singleDetectMine(LDR07));

  output.push_back(singleDetectMine(LDR08));
  output.push_back(singleDetectMine(LDR09));
  output.push_back(singleDetectMine(LDR10));
  output.push_back(singleDetectMine(LDR11));
  return output;
}

bool detectMine(){
    //Serial.println("WHERE ARE THOSE FUCKIN MINES");
    bool mineFound = false;
    int LDRCounter = 0;
    while(LDRCounter <= 8 && !mineFound){
        if (LDRCounter == 0 && singleDetectMine(LDR00) != 0){
            mineFound = true;
        }
        else if (LDRCounter == 1 && singleDetectMine(LDR01) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 2 && singleDetectMine(LDR02) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 3 && singleDetectMine(LDR03) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 4 && singleDetectMine(LDR07) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 5 && singleDetectMine(LDR08) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 6 && singleDetectMine(LDR09) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 7 && singleDetectMine(LDR10) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        else if (LDRCounter == 8 && singleDetectMine(LDR11) != 0){
            mineFound = true;
            //Serial.println("HOLY SHIT THERE@' A MINE");
        }
        LDRCounter += 1;
    }
    return mineFound;
}

void mineGrab() {
	// Grabs mine immediately in front of robot, returns 1 when complete
	// WARNING: Robot must be orientate to face the mine first
  servoMove(0);
  isHoldingMine = 1;
}

void mineDrop() {
	// Drops mine held by robot, returns 0 when complete
  servoMove(30);
  isHoldingMine = 0;
}

// **** PRIVATE **** //
