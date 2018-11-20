/*
 * movement.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * Contains algorithms for moving the robot
 */

// ** Preamble ** //
#include "orientation.h"

// **** PRIVATE **** //

float getDirection() {
    //Uses a reading from the compass and the orientated compass offset to return the robot’s angle
    //Correct reading to be relative to x-axis heading then output
    float currentHeading = compass.getHeading();
    if (compassOffset - currentHeading <= -180) {
        return round(360 + compassOffset - currentHeading);
    }
    else{
        return round (compassOffset - currentHeading);
    }
}

void setForward(int inputSpeed) {
  // Sets both motors to foward mode with the defined speeds
  leftMotor.setForward();
  rightMotor.setForward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

void setBackward(int inputSpeed) {
  // Sets both motors to backward mode with the defined speeds
  leftMotor.setBackward();
  rightMotor.setBackward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

void setStop(int stopDelay = 0) {
  // Stops both motors
  delay(stopDelay);
  leftMotor.emergencyStop();
  rightMotor.emergencyStop();
}

void setClockwise(int inputSpeed) {
  // Sets both motors to spin clockwise with the defined speeds
  leftMotor.setForward();
  rightMotor.setBackward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

void setAnticlockwise(int inputSpeed) {
  // Sets both motors to spin anticlockwise with the defined speeds
  leftMotor.setBackward();
  rightMotor.setForward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

// **** PUBLIC **** //

// ** Facing ** //

void faceAngle(float targetHeading, float tollerance = 1, int turnSpeed = 255) {
  // rotates to face in a particular direction
  float currentHeading = getDirection();
  float error = currentHeading - targetHeading;
  if (targetHeading == 180) {
    while (currentHeading >= 0 && currentHeading < 179.5) {
      currentHeading = getDirection();
      setAnticlockwise(255);
      setStop(5);
    }
    while (currentHeading <= 0 && currentHeading > -179.5) {
      currentHeading = getDirection();
      setClockwise(255);
      setStop(5);
    }
  } else {
   while (abs(error) > tollerance) {
     currentHeading = getDirection();
     error = currentHeading - targetHeading;
     if (error > 0) {
       setClockwise(turnSpeed);
     } else {
       setAnticlockwise(turnSpeed);
      }
    setStop(5);
    }
  }
}

void faceFwd() {
	// Points the robot forward relative to its course
}

void faceBwd() {
	// Points the robot backward relative to its course
}

void faceLft() {
	// Points the robot left relative to its course
}

void faceRgt() {
	// Points he robot right relative to its course
}

void faceCoord(coord input_coord) {
	// Points the robot towards the coordinate "input_coord"
}

coord getCoords(float currentDirection) {
    // Uses the ultrasound sensors to return a coord object giving the robot’s current location
    // Lengths to be given in cm
    // Direction to be given in degrees and should be oriented to the robot's Cartesian co-ordinate system

    //Initialise coordinate variables
    int xCoordinate;
    int yCoordinate;
  
    if (abs(currentDirection) <= 45){
        faceAngle(0);
        xCoordinate = xUltrasound.getReading() + ROBOT_LENGTH;
        yCoordinate = ARENA_Y - (yUltrasound.getReading() + ROBOT_WIDTH/2);
    }
    else if (currentDirection > 0 && currentDirection <= 135){
        faceAngle(90);
        xCoordinate = yUltrasound.getReading() + ROBOT_WIDTH/2;
        yCoordinate = xUltrasound.getReading() + ROBOT_LENGTH;
    }
    else if (currentDirection < 0 && currentDirection >= -135){
        faceAngle(-90);
        xCoordinate = ARENA_X - (yUltrasound.getReading() + ROBOT_WIDTH/2);
        yCoordinate = ARENA_Y - (xUltrasound.getReading() + ROBOT_LENGTH);
    }
    else{
        faceAngle(180);
        xCoordinate = ARENA_X - (xUltrasound.getReading() + ROBOT_LENGTH);
        yCoordinate = yUltrasound.getReading() + ROBOT_WIDTH/2;
    }
    coord currentCoord(xCoordinate, yCoordinate);
    return currentCoord;
}

// ** Movement ** //

void moveFwd(float input_distance) {
	// Moves the robot forward (relative to current facing) by distance "input_distance"
}

void moveBwd(float input_distance) {
	// Moved the robot backward (relative to current facing) byb distance "input_distance"
}

// ** Rotation ** //

void spinLft(float input_degrees) {
	// Rotates the robot left (anticlockwise) through angle "input_degrees"
}

void spinRgt(float input_degrees) {
	// Rotates the robot right (clockwise) through angle "input_degrees"
}

// ** Path ** //

void pathFollow(float input_distance) {
	// Moves the robot forwards along the path by distance "input_distance"
}

void pathEdge() {
	// Moves the robot to the edge of the search area via the shortest route, avoiding mines
}

void pathReturn() {
	// Moves the robot back to the point on its path where it left off, avoiding mines
}

void pathHome() {
	// Moves the robot back to the startbox via the shortest route, avoiding mines
}

void pathGo(coord inputCoord) {
	// Moves the robot to the coordinate "input_coord" via the shortest route
    coord currentCoord = getCoords(getDirection());
    coord movementVector = inputCoord.subtract(currentCoord);
    float vectorAngle;
    if (movementVector.x == 0 && movementVector.y < 0) {
        vectorAngle = -90;
    }
    else if (movementVector.x == 0 && movementVector.y >= 0){
        vectorAngle = 90;
    }
    else {
        vectorAngle = atan2(movementVector.y, movementVector.x)*180/PI;
    }
    
}

// ** Panic ** //

void panicHome() {
	// Moves the robot back to the start box, regardless of mines in the way
}

void panicEdge() {
	// Moves the to the nearest edge, regardless of mines in the way
}

void panicRun() {
	// Moves the robot in a straight line, regardless of mines, until it reaches the edge
}

void panicPanic() {
	// Moves eratically and without direction in an inescapable loop (edgecase)
}
