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