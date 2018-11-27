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
  float THDanger = 5;
  float THSafe = 20;
  if (reading >= datum + THSafe) { // SAFE
    return(1); // SAFE
  }
  if (reading > datum + THDanger && reading < datum + THSafe) {
    return(2); // DANGER
  } else {
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
}

bool detectMine(){
    bool mineFound = false;
    int LDRCounter = 0;
    while(LDRCounter <= 8 && !mineFound){
        switch(LDRCounter){
            case 0:
                if(singleDetectMine(LDR00) != 0){
                    mineFound = true;
                }
                break;
            case 1:
                if(singleDetectMine(LDR01) != 0){
                    mineFound = true;
                }
                break;
            case 2:
                if(singleDetectMine(LDR02) != 0){
                    mineFound = true;
                }
                break;
            case 3:
                if(singleDetectMine(LDR03) != 0){
                    mineFound = true;
                }
                break;
            case 4:
                if(singleDetectMine(LDR07) != 0){
                    mineFound = true;
                }
                break;
            case 5:
                if(singleDetectMine(LDR08) != 0){
                    mineFound = true;
                }
                break;
            case 6:
                if(singleDetectMine(LDR09) != 0){
                    mineFound = true;
                }
                break;
            case 7:
                if(singleDetectMine(LDR10) != 0){
                    mineFound = true;
                }
                break;
            case 8:
                if(singleDetectMine(LDR11) != 0){
                    mineFound = true;
                }
                break;
            LDRCounter += 1;
        }
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
