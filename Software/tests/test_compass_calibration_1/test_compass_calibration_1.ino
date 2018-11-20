/*
 * motorTest.h
 *
 *  Created on: 8 Nov 2018
 *      Author: lewis
 *
 *  Gets data for compass calibration
 */

#include "libraries.h"

// Assign compass to compass object
Adafruit_LSM303_Mag_Unified calibrationCompass = Adafruit_LSM303_Mag_Unified();

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

// Initialise data dump


void setup () {
    //Start compass
    calibrationCompass.begin();
}

void loop() {
    // Fetch current compass flux readings
    sensors_event_t reading;
    calibrationCompass.getEvent(&reading);

    // Assign flux readings to variables
    currentYFlux = reading.magnetic.y;
    currentXFlux = reading.magnetic.x;

    // Append flux readings to arrays
    yFluxes.push_back(currentYFlux);
    xFluxes.push_back(currentXFlux);
    
    // Check if current fluxes are maximum/minimum
    if (currentYFlux < minYFlux){
        minYFlux = currentYFlux;
    }
    if (currentYFlux > maxYFlux){
        maxYFlux = currentYFlux;
    }
    if (currentXFlux < minXFlux){
        minXFlux = currentXFlux;
    }
    if (currentYFlux > maxXFlux){
        minXFlux = currentXFlux;
    }
    Serial.print(currentXFlux);
    Serial.print(",");
    Serial.println(currentYFlux);

    delay(100);
}
