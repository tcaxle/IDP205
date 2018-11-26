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

bool detectMine() {
  
}

bool mineGrab() {
	// Grabs mine immediately in front of robot, returns 1 when complete
	// WARNING: Robot must be orientate to face the mine first
}

bool mineDrop() {
	// Drops mine held by robot, returns 0 when complete
}

bool mineColourRed() {
	// Returns a 1 if colour sensors pick up red object, else 0
}

bool mineColourGrn() {
	// Returns a 1 if colour sensors pick up a green object, else 0
}

// **** PRIVATE **** //
