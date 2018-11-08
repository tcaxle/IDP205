/*
 * classes.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the declaration of classes
 */

// Preamble
#include <Adafruit_MotorShield.h>
#include <Arduino.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Wire.h>

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
    Adafruit_DCMotor thisMotor;
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
