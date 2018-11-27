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