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

// ** LOCATE ** //

coord getCoords(float currentDirection = getDirection()) {
    // Uses the ultrasound sensors to return a coord object giving the robot’s current location
    // Lengths to be given in cm
    // Direction to be given in degrees and should be oriented to the robot's Cartesian co-ordinate system

    //Initialise coordinate variables
    int xCoordinate;
    int yCoordinate;
  
    if (abs(currentDirection) <= 45){
        faceAngle(0);
        xCoordinate = xUltrasound.getReading() + ROBOT_LENGTH;
        yCoordinate = arena.y1 - (yUltrasound.getReading() + ROBOT_WIDTH/2);
    }
    else if (currentDirection > 0 && currentDirection <= 135){
        faceAngle(90);
        xCoordinate = yUltrasound.getReading() + ROBOT_WIDTH/2;
        yCoordinate = xUltrasound.getReading() + ROBOT_LENGTH;
    }
    else if (currentDirection < 0 && currentDirection >= -135){
        faceAngle(-90);
        xCoordinate = arena.x1 - (yUltrasound.getReading() + ROBOT_WIDTH/2);
        yCoordinate = arena.y1 - (xUltrasound.getReading() + ROBOT_LENGTH);
    }
    else{
        faceAngle(180);
        xCoordinate = arena.x1 - (xUltrasound.getReading() + ROBOT_LENGTH);
        yCoordinate = yUltrasound.getReading() + ROBOT_WIDTH/2;
    }
    coord currentCoord(xCoordinate, yCoordinate);
    return currentCoord;
}