/*
 * orientation.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * Contains functions to generate and manipulate 
 * cartesian coordinate system and polygon objects
 * used in pathing algorithms
 */

// ** Preamble ** //

// **** PUBLIC **** //

coords getCoords(float areaX, float areaY, float robotLength, float robotWidth, float currentDirection) {
    // Uses the ultrasound sensors to return a coord object giving the robot’s current location
	// Lengths to be given in cm
	// Direction to be given in degrees and should be oriented to the robot's Cartesian co-ordinate system
	if (abs(currentDirection) <= 45){
		faceX+();
		xCoordinate = xUltrasound.getReading() + robotLength;
		yCoordinate = areaY - (yUltrasound.getReading() + robotWidth/2);
	}
	else if (currentDirection > 0) && (currentDirection <= 135){
		faceY+();
		xCoordinate = yUltrasound.getReading() + robotWidth/2;
		yCoordinate = xUltrasound.getReading() + robotLength;
	}
	else if (currentDirection < 0) && (currentDirection >= -135){
		faceY-();
		xCoordinate = areaX - (yUltrasound.getReading() + robotWidth/2);
		yCoordinate = areaY - (xUltrasound.getReading() + robotLength);
	}
	else{
		faceX-();
		xCoordinate = areaX - (xUltrasound.getReading + robotLength);
		yCoordinate = yUltrasound.getReading() + robotWidth/2;
	}
	coord currentCooord(xCoordinate, yCoordinate);
	return currentCoord;
}


int getDirection(float currentHeading, compassOffset = 0) {
    //Uses a reading from the compass and the orientated compass offset to return the robot’s angle
	//Correct reading to be relative to x-axis heading then output
	if (compassOfsset - compassReading <= -180) {
		return round(360 + compassOffset - currentHeading);
	}
	else{
		return round (compassOffset - currentHeading);
	}
}
*/

// **** PRIVATE **** //
