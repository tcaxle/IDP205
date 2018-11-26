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

float getDirection() {
    //Uses a reading from the compass and the orientated compass offset to return the robot’s angle
    //Correct reading to be relative to x-axis heading then output
    float currentHeading = compass.getHeading();
    if (compassOffset - currentHeading <= -180) {
        return round(360 + compassOffset - currentHeading);
    }
    else if (compassOffset - currentHeading > 180){
        return round(compassOffset - currentHeading - 360);
    }
    else{
        return round (compassOffset - currentHeading);
    }
}

void setFwd(int inputSpeed = 90) {
  // Sets both motors to foward mode with the defined speeds
  leftMotor.setForward();
  rightMotor.setForward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

void setBwd(int inputSpeed = 90) {
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

void setClockwise(int inputSpeed = 120) {
  // Sets both motors to spin clockwise with the defined speeds
  leftMotor.setForward();
  rightMotor.setBackward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

void setAnticlockwise(int inputSpeed = 120) {
  // Sets both motors to spin anticlockwise with the defined speeds
  leftMotor.setBackward();
  rightMotor.setForward();
  leftMotor.setSpeed(inputSpeed);
  rightMotor.setSpeed(inputSpeed);
}

// **** PUBLIC **** //

// ** Facing ** //

void faceAngle(float targetHeading, float tolerance = 0.25, int turnSpeed = 60) {
  // rotates to face in a particular direction
  float currentHeading = getDirection();
  float error = currentHeading - targetHeading;
  if (targetHeading == 180) {
    while (currentHeading >= 0 && currentHeading < 179.5) {
      currentHeading = getDirection();
      setAnticlockwise(turnSpeed);
      setStop(5);
    }
    while (currentHeading <= 0 && currentHeading > -179.5) {
      currentHeading = getDirection();
      setClockwise(turnSpeed);
      setStop(5);
    }
  } else {
   while (abs(error) > tolerance) {
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
  setStop();
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
	// Points the robot right relative to its course
}

void faceCoord(coord input_coord) {
	// Points the robot towards the coordinate "input_coord"
}

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
        yCoordinate = ARENA_WIDTH - (yUltrasound.getReading() + ROBOT_WIDTH/2);
    }
    else if (currentDirection > 0 && currentDirection <= 135){
        faceAngle(90);
        xCoordinate = yUltrasound.getReading() + ROBOT_WIDTH/2;
        yCoordinate = xUltrasound.getReading() + ROBOT_LENGTH;
    }
    else if (currentDirection < 0 && currentDirection >= -135){
        faceAngle(-90);
        xCoordinate = ARENA_WIDTH - (yUltrasound.getReading() + ROBOT_WIDTH/2);
        yCoordinate = ARENA_WIDTH - (xUltrasound.getReading() + ROBOT_LENGTH);
    }
    else{
        faceAngle(180);
        xCoordinate = ARENA_WIDTH - (xUltrasound.getReading() + ROBOT_LENGTH);
        yCoordinate = yUltrasound.getReading() + ROBOT_WIDTH/2;
    }
    coord currentCoord(xCoordinate, yCoordinate);
    return currentCoord;
}

// ** Movement ** //

void moveFwd(float inputDistance) {
	// Moves the robot forward (relative to current facing) by distance "inputDistance"
    int startDistance = xUltrasound.getReading();
    int currentDistance;
    int distanceTravelled;
    int error = inputDistance;
    while(abs(error) > 0){
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
    Serial.print("Distance travelled: ");
    Serial.println(distanceTravelled);
    Serial.println();
}

void moveBwd(float inputDistance) {
	// Moved the robot backward (relative to current facing) byb distance "inputDistance"
}

// ** Rotation ** //

void spinLft(float inputDegrees) {
	// Rotates the robot left (anticlockwise) through angle "inputDegrees"
}

void spinRgt(float inputDegrees) {
	// Rotates the robot right (clockwise) through angle "inputDegrees"
}

// ** Path ** //

void pathGo(coord inputCoord, int tolerance = 2){
    // Moves the robot to the coordinate "input_coord" via perpendicular components
    // Get current position
    coord currentCoord = getCoords(getDirection());
    Serial.print("Starting X Coord: ");
    Serial.println(currentCoord.x);
    Serial.print("Starting Y Coord: ");
    Serial.println(currentCoord.y);
    Serial.println();
    // Calculate vector from current position to target position
    coord movementVector = inputCoord.subtract(currentCoord);
    Serial.print("Movement X Component: ");
    Serial.println(movementVector.x);
    Serial.print("Movement Y Component: ");
    Serial.println(movementVector.y);
    Serial.println();
    if(movementVector.x > tolerance){
        faceAngle(0);
        Serial.println("Turning to +x");
        Serial.print("Current direction: ");
        Serial.println(getDirection());
        Serial.println();
        moveFwd(abs(movementVector.x));
    }
    else if(movementVector.x < -tolerance){
        faceAngle(180);
        Serial.println("Turning to -x");
        Serial.print("Current direction: ");
        Serial.println(getDirection());
        Serial.println();
        moveFwd(abs(movementVector.x));
    }
    if(movementVector.y > tolerance){
        faceAngle(90);
        Serial.println("Turning to +y");
        Serial.print("Current direction: ");
        Serial.println(getDirection());
        Serial.println();
        moveFwd(abs(movementVector.y));
    }
    else if(movementVector.y < -tolerance){
        faceAngle(-90);
        Serial.println("Turning to -y");
        Serial.print("Current direction: ");
        Serial.println(getDirection());
        Serial.println();
        moveFwd(abs(movementVector.y));
    }
    //faceAngle(xOrientation);
    Serial.print("End direction: ");
    Serial.println(getDirection());
    Serial.println();
    currentCoord = getCoords(getDirection());
        Serial.print("End X Coord: ");
    Serial.println(currentCoord.x);
    Serial.print("End Y Coord: ");
    Serial.println(currentCoord.y);
}

/*
void pathGo(coord inputCoord) {
    // Moves the robot to the coordinate "input_coord" via the shortest route
    // Get current position
    coord currentCoord = getCoords(getDirection());
    // Calculate vector from current position to target position
    coord movementVector = inputCoord.subtract(currentCoord);
    // Initialise containers for angle and length of vector
    float vectorAngle;
    int vectorLength;
    // If the vector to the target is vertical
    if (movementVector.x == 0 && movementVector.y < 0) {
        // If the y-component is negative, the angle is -90 degress from the neutral axis
        vectorAngle = -90;
    }
    else if (movementVector.x == 0 && movementVector.y >= 0){
        // If the y-component is positive, the angle is 90 degrees from the neutral axis
        vectorAngle = 90;
    }
    else {
        // Otherwise find the angle from the neutral axis by inverse tangent
        vectorAngle = atan2(movementVector.y, movementVector.x)*180/PI;
    }
    faceAngle(vectorAngle);
    // Calculate length to move by Pythagoras
    vectorLength = round(sqrt(pow(movementVector.x, 2) + pow(movementVector.y, 2)));
    moveFwd(vectorLength);
    currentCoord = getCoords(getDirection());
    Serial.print(currentCoord.x);
    Serial.print(", ");
    Serial.println(currentCoord.y);
}*/

void pathFollow(vector<coord> path) {
	// Moves the robot forwards along the path by distance "inputDistance", avoiding mines
    // Doesn't currently avoid mines
    int pathSize = path.size();
    for (int coordCounter = 0; coordCounter < pathSize; coordCounter += 1){
        coord nextCoord = path.back();
        Serial.print("Next co-ord: ");
        Serial.print(nextCoord.x);
        Serial.print(", ");
        Serial.println(nextCoord.y);
        Serial.println();
        pathGo(nextCoord);
        path.pop_back();
    }
}

void pathEdge() {
	// Moves the robot to the edge of the search area via the shortest route, avoiding mines
}

void pathReturn() {
	// Moves the robot back to the point on its path where it left off, avoiding mines
}

// ** PATH GENERATION ** //

vector<coord> generateSearchPath(int gap = 20) {
  // Generates a series of (20cm spaced by default) coordinates along input y line to follow, ends before it hits the wall.
  // Will generate to go to ****furthest side**** from current position
  // Requires to be predefined: dangerZone (rectangle)
  coord currentPosition = getCoords();
  coord lastCoord;
  vector<coord> path;
  if (xOrientation == 0){
    lastCoord = coord(dangerZone.x1, currentPosition.y);
    while(lastCoord.x > currentPosition.x){
        path.push_back(lastCoord);
        lastCoord.x -= gap;
    }
  }
  else{
    lastCoord = coord(dangerZone.x0, currentPosition.y);
    while(lastCoord.x < currentPosition.x){
        path.push_back(lastCoord);
        lastCoord.x += gap;
    }
  }
  return path;
}

vector<coord> generateEdgePath(int gap = 20) {
  // Generates a series of coordinates to go (20cm spacing by default) to the closest wall and return to original space
  // Will generate to go to closest X or the y=0 side (whichever is closest)
  // Requires to be predefined: arena (rectangle), dangerZone (rectangle)
  coord currentPosition = getCoords();
  coord lastCoord;
  int lastX;
  int lastY;
  vector<coord> path;
  // If facing positive x-direction
  if (xOrientation == 0) {
    // If closer to bottom edge of danger zone than vertical edge
    if ((currentPosition.y - dangerZone.y0) < (currentPosition.x - dangerZone.x0)) {
      // follow constant X line from robot to edge, y decreasing
      lastCoord = coord(currentPosition.x, currentPosition.y);
      while (lastCoord.y >= dangerZone.y0) {
        path.push_back(lastCoord);
        lastCoord.y -= gap;
      } 
      lastCoord = coord(currentPosition.x, dangerZone.y0);
      path.push_back(lastCoord);
      // follow constant X line back to original position, y increasing
      lastCoord = coord(currentPosition.x, dangerZone.y0 + gap);
      while (lastCoord.y < currentPosition.y) {
        path.push_back(lastCoord);
        lastCoord.y += gap;
      } 
      return path;
      } 
      // Otherwise (ie: if closer to vertical edge than bottom edge)
      else {
      // follow constant Y line from robot to edge, x decreasing
      lastCoord = coord(currentPosition.x, currentPosition.y);
      while (lastCoord.x >= dangerZone.x0) {
        path.push_back(lastCoord);
        lastCoord.x -= gap;
      }
      lastCoord = coord(dangerZone.x0, currentPosition.y);
      path.push_back(lastCoord);
      // follow constant Y line back to original position, x increasing
      lastCoord = coord(dangerZone.x0 + gap, currentPosition.y);
      while (lastCoord.x < currentPosition.x) {
        path.push_back(lastCoord);
        lastCoord.x += gap;
      }
      return path;
    }
  }
    // Otherwise, if facing negative x-direction 
  else {
    if (currentPosition.y - dangerZone.y0 < dangerZone.x1 - currentPosition.x) {
      // follow constant X line from robot to edge, y decreasing
      lastCoord = coord(currentPosition.x, currentPosition.y);
      while (lastCoord.y >= dangerZone.y0) {
        path.push_back(lastCoord);
        lastCoord.y -= gap;
      } 
      lastCoord = coord(currentPosition.x, dangerZone.y0);
      path.push_back(lastCoord);
      // follow constant X line back to original position, y increasing
      lastCoord = coord(currentPosition.x, dangerZone.y0 + gap);
      while (lastCoord.y < currentPosition.y) {
        path.push_back(lastCoord);
        lastCoord.y += gap;
      } 
      return path;
      }
      else {
      // follow constant Y line from robot to edge, x increasing
      lastCoord = coord(currentPosition.x, currentPosition.y);
      while (lastCoord.x <= dangerZone.x1) {
        path.push_back(lastCoord);
        lastCoord.x += gap;
      }
      lastCoord = coord(dangerZone.x1, currentPosition.y);
      path.push_back(lastCoord);
      // follow constant Y line back to original position, x decreasing
      lastCoord = coord(dangerZone.x1 - gap, currentPosition.y);
      while (lastCoord.x < currentPosition.x) {
        path.push_back(lastCoord);
        lastCoord.x -= gap;
      }
      return path;
    }
  }
}

vector<coord> generateHomePath(int gap = 20){
    // Generates a series of coordinates to go (20cm spacing by default) back to the robot's starting position
    coord currentPosition = getCoords();
    coord lastCoord;
    vector<coord> path;
    if (currentPosition.x == homeCoord.x){
        lastCoord = homeCoord;
        // Proceed along current X line with decreasing Y
        while (lastCoord.y < currentPosition.y){
            path.push_back(lastCoord);
            lastCoord.y += gap;
        }
    }
    else{
        int homeLineGradient = round((currentPosition.y - homeCoord.y)/(currentPosition.x - homeCoord.x));
        lastCoord = homeCoord;
        // Proceed along line from homeCoord to currentPosition
        while (lastCoord.y < currentPosition.y){
            path.push_back(lastCoord);
            lastCoord.y += round((homeLineGradient*gap)/sqrt(pow(homeLineGradient, 2) + 1))
            lastCoord.x += round((gap)/sqrt(pow(homeLineGradient, 2) + 1));
        }
    }
}

// ** SETUP ** //

float initialiseOrientation(){
    /*
    int currentXMeasurement = xUltrasound.getTime();
    int lastXMeasurement = currentXMeasurement;
    float offsetAngle;
    setClockwise(60);
    while (currentXMeasurement <= lastXMeasurement + 5){
        lastXMeasurement = currentXMeasurement;
        currentXMeasurement = xUltrasound.getTime();
    }
    setStop();
    delay(500);
    currentXMeasurement = xUltrasound.getTime();
    lastXMeasurement = currentXMeasurement;
    setAnticlockwise(60);
    while(currentXMeasurement <= lastXMeasurement + 5){
        lastXMeasurement = currentXMeasurement;
        currentXMeasurement = xUltrasound.getReading();
    }
    setStop();
    offsetAngle = compass.getHeading();
    return offsetAngle;
    */
    return compass.getHeading();
}

/*
vector<int> initialiseArenaBoundaries(){
    // To be called after initialiseOrientation
    int distToYAxis;
    int distToXAxis;
    int distToFarY;
    int distToFarX;
    int totalX;
    int totalY;
    vector<int> arenaBoundaries;
    faceAngle(0);
    distToYAxis = xUltrasound.getReading() + ROBOT_LENGTH;
    distToFarX = yUltrasound.getReading();
    faceAngle(180);
    distToFarY = xUltrasound.getReading();
    distToXAxis = yUltrasound.getReading() + ROBOT_WIDTH/2;
    faceAngle(0);
    totalX = distToXAxis + distToFarX;
    totalY = distToYAxis + distToFarY;
    arenaBoundaries.push_back(totalX);
    arenaBoundaries.push_back(totalY);
    return arenaBoundaries;
}*/

//RECTANGLE OUTPUT
rectangle initialiseArenaBoundaries(){
    // To be called after initialiseOrientation
    int distToYAxis;
    int distToXAxis;
    int distToFarY;
    int distToFarX;
    int totalX;
    int totalY;
    rectangle arena;
    faceAngle(0);
    distToYAxis = xUltrasound.getReading() + ROBOT_LENGTH;
    distToFarX = yUltrasound.getReading();
    faceAngle(180);
    distToFarY = xUltrasound.getReading();
    distToXAxis = yUltrasound.getReading() + ROBOT_WIDTH/2;
    totalX = distToXAxis + distToFarX;
    totalY = distToYAxis + distToFarY;
    arena = rectangle(0, totalX, 0, totalY);
    return arena;
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
