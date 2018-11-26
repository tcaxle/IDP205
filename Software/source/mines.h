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
bool isHoldingMine = 0; // A flag to indicate whether or not the robot is holding a mine

// ** Mine Interaction ** //
void calibrateLDRs() {
  // ONLY CALL WHEN ALL LDRS OVER BLACK
  LDR00.calibrate();
  LDR01.calibrate();
  LDR02.calibrate();
  LDR03.calibrate();
  LDR04.calibrate();

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

vector<int> detectMine() {
  vector<int> output;
  output.push_back(singleDetectMine(LDR00));
  output.push_back(singleDetectMine(LDR01));
  output.push_back(singleDetectMine(LDR02));
  output.push_back(singleDetectMine(LDR03));
  output.push_back(singleDetectMine(LDR04));

  output.push_back(singleDetectMine(LDR08));
  output.push_back(singleDetectMine(LDR09));
  output.push_back(singleDetectMine(LDR10));
  output.push_back(singleDetectMine(LDR11));
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
