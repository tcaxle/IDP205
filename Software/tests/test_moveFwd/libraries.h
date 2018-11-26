/* 
 * libraries.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * A set of #inlcude statements for external
 * libraries and repositories needed by the program
 */

// ** Globals ** //
#include <Arduino.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_Sensor.h>
#include <ArduinoSTL.h>
#include <Wire.h>
#include <NewPing.h>

// ** Locals ** //
#include "utility/Adafruit_MS_PWMServoDriver.h"

using namespace std;

// ** Constants ** //
#define PI 3.14159265359
#define IR_SCALE 26
