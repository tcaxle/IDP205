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
vector<bool> calibrateLDRs() {
  
}


bool singleDetectMine(char port) {
  
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
