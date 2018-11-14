/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

// ** Preamble ** //
#include <Adafruit_MotorShield.h>
#include <Arduino.h>
#include <NewPing.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Wire.h>

// **** PUBLIC **** //

class digital_output {
public:
	int pin;
	bool default_status, status;
	void init () {
		// sets the relevant pin to be an output
		pinMode(pin, OUTPUT);
		status = default_status;
		digitalWrite(pin, status);
	}
	void set_default () {
		// sets the output to the default value
		status = default_status;
		digitalWrite(pin, status);
	}
	void set (bool new_status) {
		// sets output to on or off
		status = new_status;
		digitalWrite(pin, status);
	}
	bool get () {
		// returns current state
		return status;
	}
};

class led {
  public:
    int pin;
    bool status;
    void init(){
      //assigns pin to LED
      pinMode(pin, OUTPUT);
      status = 0;
      digitalWrite(pin, status);
    }
    void set(bool newStatus){
      //change led to on/off
      status = newStatus;
      digitalWrite(pin, status);
    }
};

class motor{
  public:
    int port, speed;
    Adafruit_DCMotor *thisMotor;
    Adafruit_MotorShield assignedMotorShield;
  void init(){
    //creates ada-fruit object and assigns to port with initial speed 0
    thisMotor = assignedMotorShield.getMotor(port);
    speed = 0;
    thisMotor->setSpeed(speed);
  }
  void setSpeed(int newSpeed){
    //sets new speed for the motor
    speed = newSpeed;
    thisMotor->setSpeed(speed);
  }
  void setForward(){
    //sets motor to forward direction
    thisMotor->run(FORWARD);
  }
  void setBackward(){
    //sets motor to backward direction
    thisMotor->run(BACKWARD);
  }
  void emergencyStop(){
    //stops motor immediately and resets speed to zero
    thisMotor->run(RELEASE);
    speed = 0;
    thisMotor->setSpeed(speed);
  }
};

class coord {
	public:
		int x, y;
		coord add(coord inputCoord) {
			// Returns a coordinate that is the original plus the input elementwise
			coord outputCoord;
			outputCoord.x = x + inputCoord.x;
			outputCoord.y = y + inputCoord.y;
			return outputCoord;
		}
		coord subtract(coord inputCoord) {
			// Returns a coordinate that is the original minus the input elementwise
			coord outputCoord;
			outputCoord.x = x - inputCoord.x;
			outputCoord.y = y - inputCoord.y;
			return outputCoord;
		}
		float distance(coord inputCoord) {
			// Returns the distance between two coordinates
			coord difference = subtract(inputCoord);
			return pow(pow(difference.x,2) + pow(difference.y,2), 0.5);
    		}
};

class rectangle {
	/* A class used to denote "keepout zones"
	 *     x0    x1
	 *      |    |
	 *  y1--a----b--
	 *      |    |
	 *  y0--c----d--
	 *      |    |
	 */
	public:
		int x0, x1, y0, y1;
		coord a, b, c, d;
		void init() {
			// Creates the coordinates for the corners, a, b, c, d (see diagram above)
			a.x = x0; a.y = y1;
			b.x = x1; b.y = y1;
			c.x = x0; c.y = y0;
			d.x = x1; d.y = y0;
		}
		bool insideRectangle(coord inputCoord) {
			// Returns True if "inputCoord" is inside the rectangle object. Else returns False.
			if ( (inputCoord.x > x0 && inputCoord.x < x1) || (inputCoord.y > y0 && inputCoord.y < y1) ) {
				return 1;
			} else {
				return 0;
			}
		}
		coord nearestCorner(coord inputCoord) {
			// Returns the coordinate of the nearest corner to the "inputCoord"
			coord corner = a;
			if (inputCoord.distance(b) < inputCoord.distance(corner)) {
				corner = b;
			}
			if (inputCoord.distance(c) < inputCoord.distance(corner)) {
				corner = c;
			}
			if (inputCoord.distance(d) < inputCoord.distance(corner)) {
				corner = d;
			}
			return corner;
		}
};

class ultrasoundSensor{
  public:
    int triggerPin, echoPin, maxDistance, pingInterval;
    NewPing thisUltrasoundSensor;
  void init(){
    thisUltrasoundSensor.trigger_pin = triggerPin;
    thisUltrasoundSensor.echo_pin = echoPin;
    thisUltrasoundSensor.max_cm_distabce = maxDistance;
  }
  int getDistance(){
    thisUltrasoundSensor.ping_cm();
  }
};

// **** PRIVATE **** //

>>>>>>> c755af73331318f8165df49fd4c760d464d54c1f
