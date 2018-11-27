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

// ** Movement ** //


// ** Rotation ** //

void spinLft(float inputDegrees) {
	// Rotates the robot left (anticlockwise) through angle "inputDegrees"
}

void spinRgt(float inputDegrees) {
	// Rotates the robot right (clockwise) through angle "inputDegrees"
}

// ** Path ** //



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
            lastCoord.y += round((homeLineGradient*gap)/sqrt(pow(homeLineGradient, 2) + 1));
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
