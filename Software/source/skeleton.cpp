/*
 * skeleton.cpp
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * The basic loop listing subroutines for normal use
 *
 */



void main() {
	
	// Setup:		
	orientate(); // Orientate robot to find origin of cartesian reference	
	initialiseBoundary(); // Create the boundary polygon that is the search zone
	faceForward(); // Orientate the robot in the positive Path Direction (a function of its location + history)

	// Main loop
	while ( time < MAXTIME ) {

		ledCtrl.setNone();			// Indicate no mine present

		while ( mineCheck() == 0 ) {
			pathFollow(); 			// Follow the path, marks cleared region in polygon
		} 
	
		// Mine Detected:
		faceMine+();				// Bring mine within colour sensing range
		cout << mineLocate(); 			// Output the location of the mine that has been found
		if ( mineColourRed() == 1 ) { 		// Check if mine is red
			ledCtrl.setDang(); 		// Indicate dangerous mine
			delay(3);			// Wait 3s
			pathAvoid(); 			// Execute mine avoidance algorithm that returns it to its path ASAP
		} else { 				// If not red, assume green
			ledCtrl.setSafe(); 		// Indicate safe mine
			delay(3);			// Wait 3s
			mineCollect(); 			// Collect the mine for disposal
			pathEdge();			// Move to edge of boundary by shortest route avoiding mines 
			mineDispose(); 			// Deposit mine outside of boundary
			pathReturn(); 			// Return to path
		}
	}

	pathHome(); // Return to startbox
}
