/*
 * motorTest.h
 *
 *  Created on: 20 Nov 2018
 *      Author: lewis
 *
 *  Gets data for compass calibration
 */

#include "libraries.h"
#include "classes.h"

// Assign compass to compass object
Adafruit_LSM303_Mag_Unified calibrationCompass = Adafruit_LSM303_Mag_Unified();

// Assigns motors to motor objects
Adafruit_MotorShield motorShield = Adafruit_MotorShield();
motor leftMotor(3); // Motor on port 1 and initial speed 0 (default third parameter)
motor rightMotor(4); // Motor on port 2 and initial speed 0 (default third parameter)

// Initialise counter variable
int runCounter = 0;

// Initialise flux variables
float currentYFlux;
float currentXFlux;


// Initialise superlative flux variables
float maxYFlux = .0;
float maxXFlux = .0;
float minYFlux = .0;
float minXFlux = .0;

// Initialise results vectors
vector<float> yFluxes;
vector<float> xFluxes;

void setup () {
    //Start serial transmission
    Serial.begin(9600);

    //Start compass
    calibrationCompass.begin();
    Serial.println("Set-up Complete!");

    // Initialise motor shield
    motorShield.begin();
    leftMotor.assignedMotorShield = motorShield;
    rightMotor.assignedMotorShield = motorShield;
    leftMotor.init();
    rightMotor.init();
}

void loop() {
    if (runCounter < 300) {
        leftMotor.setSpeed(225);
        rightMotor.setSpeed(225);
        leftMotor.setForward();
        rightMotor.setBackward();
        
        // Fetch current compass flux readings
        sensors_event_t reading;
        calibrationCompass.getEvent(&reading);

        // Assign flux readings to variables
        currentYFlux = reading.magnetic.y;
        currentXFlux = reading.magnetic.x;
        
        // Print current fluxes to serial
        Serial.print(currentXFlux);
        Serial.print(",");
        Serial.println(currentYFlux);

        // Increment runCounter
        runCounter += 1;

        delay(100);
    }
    else if (runCounter < 600){
        leftMotor.setSpeed(225);
        rightMotor.setSpeed(225);
        leftMotor.setBackward();
        rightMotor.setForward();
        
        // Fetch current compass flux readings
        sensors_event_t reading;
        calibrationCompass.getEvent(&reading);

        // Assign flux readings to variables
        currentYFlux = reading.magnetic.y;
        currentXFlux = reading.magnetic.x;
        
        // Print current fluxes to serial
        Serial.print(currentXFlux);
        Serial.print(",");
        Serial.println(currentYFlux);

        // Increment runCounter
        runCounter += 1;

        delay(100);
    }
    else {
        leftMotor.emergencyStop();
        rightMotor.emergencyStop();  
    }
}
