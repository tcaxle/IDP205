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

void moveFwd(float inputDistance, bool safe = true) {
	// Moves the robot in the current direction by distance "inputDistance" (may take negative values to reverse)
    // If the robot encounters a mine it should reverse to its previous spot
    int startDistance = xUltrasound.getReading();
    int currentDistance;
    int distanceTravelled;
    int error = inputDistance;
    // So long as the robot hasn't moved the exact distance specified and no mines are detected
    while(abs(error) > 0 && !(detectMine && safe)){
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
}

void pathGo(coord inputCoord, int tolerance = 2){
    // Moves the robot to the coordinate "input_coord" via perpendicular components
    // Get current position
    coord currentCoord = getCoords(getDirection());
    // Calculate vector from current position to target position
    coord movementVector = inputCoord.subtract(currentCoord);
    if(movementVector.x > tolerance){
        faceAngle(0);
        moveFwd(abs(movementVector.x));
    }
    else if(movementVector.x < -tolerance){
        faceAngle(180);
        moveFwd(abs(movementVector.x));
    }
    if(movementVector.y > tolerance){
        faceAngle(90);
        moveFwd(abs(movementVector.y));
    }
    else if(movementVector.y < -tolerance){
        faceAngle(-90);
        moveFwd(abs(movementVector.y));
    }
    //faceAngle(xOrientation);
    currentCoord = getCoords(getDirection());
}

void pathFollow(vector<coord> path) {
	// Moves the robot to the next point on a path, avoiding mines
    // Doesn't currently avoid mines
    coord nextCoord = path.back();
    pathGo(nextCoord);
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
	// Moves eratically and without direction in an inescapable loop (edgecase)
}
