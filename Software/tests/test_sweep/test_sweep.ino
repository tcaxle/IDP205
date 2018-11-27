/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

void servoMove(int endPos, int startPos = myservo.read(), int stepDelay = 50, int stepDegree = 1) {
  int currentPos;
  if (startPos < endPos) {
    for (currentPos = startPos; currentPos <= endPos; currentPos += stepDegree) {
      myservo.write(currentPos);
      delay(15);
    }
  } else {
    for (currentPos = startPos; currentPos >= endPos; currentPos -= stepDegree) {
      myservo.write(currentPos);
      delay(15);
    }
  }
}

void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  servoMove(0);
}
