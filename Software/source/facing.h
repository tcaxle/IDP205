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

// ** FACING ** //

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

void faceAngle(float targetHeading, float tolerance = 0.5, int turnSpeed = 60) {
  // rotates to face in a particular direction
  float currentHeading = getDirection();
  float error = currentHeading - targetHeading;
  if (targetHeading == 180) {
    while (abs(currentHeading) < 180 - tolerance) {
      Serial.println(currentHeading);
      if (180 - currentHeading <= 180){
        setAnticlockwise(turnSpeed);
      }
      else{
        setClockwise(turnSpeed);
      }
      currentHeading = getDirection();
    }
    setStop();
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
