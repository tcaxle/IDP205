/*
 * movement.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * Contains algorithms for moving the robot
 */

// ** Preamble ** //

// **** PRIVATE **** //

// **** PUBLIC **** //

// ** Movement ** //

bool moveFwd(float inputDistance) {
  // Moves the robot forward (relative to current facing) by distance "inputDistance"
  // returns false if there is a mine
    int startDistance = xUltrasound.getReading();
    int currentDistance;
    int distanceTravelled;
    int error = inputDistance;
    while(abs(error) > 0 && !detectMine()){
        currentDistance = xUltrasound.getReading();
        distanceTravelled = currentDistance - startDistance;
        error = inputDistance - distanceTravelled;
        if (error > 0){
            setFwd();
        }
        else if (error < 0){
            setBwd();
        }
        else{
            setStop();
        }
    }
    setStop();
    if (detectMine()) {
      return(0);
    } else {
      return(1);
    }
}

bool pathGo(coord inputCoord, int tolerance = 2){
    // Moves the robot to the coordinate "input_coord" via perpendicular components
    // Get current position
    // return false if there is a mine that stops it
    coord currentCoord = getCoords(getDirection());
    // Calculate vector from current position to target position
    coord movementVector = inputCoord.subtract(currentCoord);
    bool success = 1;
    if(movementVector.x > tolerance){
        faceAngle(0);
        success = moveFwd(abs(movementVector.x));
    }
    else if(movementVector.x < -tolerance){
        faceAngle(180);
        success = moveFwd(abs(movementVector.x));
    }
    if(movementVector.y > tolerance){
        faceAngle(90);
        success = moveFwd(abs(movementVector.x));
    }
    else if(movementVector.y < -tolerance){
        faceAngle(-90);
        success = moveFwd(abs(movementVector.x));
    }
    //faceAngle(xOrientation);
    currentCoord = getCoords(getDirection());
    return(success);
}

void pathFollow(vector<coord> path) {
	// Moves the robot to the next point on a path, avoiding mines
    // Doesn't currently avoid mines
    coord nextCoord = path.back();
    if (!pathGo(nextCoord)){
        delay(3000);
        coord currentPosition = getCoords().x;
        vector<int> mineReadings = getMineReadings();
        int mostExtremeReading = 2;
        for (int readingCounter = 0; readingCounter < mineReadings.size(); readingCounter += 1){
            if (mineReadings[readingCounter] == 1){
                mostExtremeReading = 1;
            }
        }
        if (mostExtremeReading == 1){
            safeMineCoords.push_back(currentPosition);
        }
        else if (mostExtremeReading == 2){
            dangerousMineCoords.push_back(currentPosition);
            forbiddenZones.push_back(rectangle(currentPosition.x - 20, currentPosition.x +20, currentPosition.y - 20, currentPosition.y + 20));
            moveFwd(-20);
        }
    }
    path.pop_back();
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
  int rndangle = random (30, 90);
  servoMove(rndangle);
	int selection = random(0, 4);
  if (selection == 0) {
    int rndspeed = random(0, 255);
    setFwd(rndspeed);
  } else if (selection == 1) {
    int rndspeed = random(0, 255);
    setBwd(rndspeed);
  } else if (selection == 2) {
    int rndspeed = random(0, 255);
    setClockwise(rndspeed);
  }
  else if (selection == 3) {
    int rndspeed = random(0, 255);
    setAnticlockwise(rndspeed);
  } else if (selection == 4) {
    setStop();
  }
  int rnddelay = random(100, 2000);
  delay(rnddelay);
}
