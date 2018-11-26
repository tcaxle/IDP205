// Sharp IR GP2Y0A41SK0F Distance Test

// http://tinkcore.com/sharp-ir-gp2y0a41-skf/

#define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)
#define IR_SCALE 20

void setup() {
  Serial.begin(9600); // start the serial port
}

void loop() {
  // 5v
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  float distance = IR_SCALE*pow(volts, -1); // worked out from datasheet graph
  delay(100); // slow down serial port 
  Serial.println(distance);   // print the distance

}
