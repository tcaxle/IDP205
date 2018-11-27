/*
 * firmware.h
 *
 * Created: 7/11/2018
 * Author: T. Crossley
 *
 * For the creation of an interface between electronic
 * (Arduino Mega) and software for greater versatility
 *
 */

// Preamble

/* Pinouts of Arduino Mega:
 *
 * Funcion:				Name:	Pin #:
 *
 * Analog 				A0		54
 * Analog 				A1		55
 * Analog 				A2		56
 * Analog 				A3		57
 * Analog 				A4		58
 * Analog 				A5		59
 * Analog 				A6		60
 * Analog	  			A7		61
 *
 * Analog 				A8		62
 * Analog 				A9		63
 * Analog 				A10		64
 * Analog 				A11		65
 * Analog 				A12		66
 * Analog		  		A13		67
 * Analog		  		A14		68
 * Analog		  		A15		69
 *
 * Digital				D22		22
 * Digital				D23		23
 * Digital				D24		24
 * Digital				D25		25
 * Digital				D26		26
 * Digital				D27		27
 * Digital				D28		28
 * Digital 				D29		29
 * Digital				D30		30
 * Digital				D31		31
 * Digital				D32		32
 * Digital				D33		33
 * Digital				D34		34
 * Digital				D35		35
 * Digital				D36		36
 * Digital				D37		37
 * Digital				D38		38
 * Digital				D39		39
 * Digital				D40		40
 * Digital				D41		41
 * Digital				D42		42
 * Digital				D43		43
 * Digital, PWM			D44		44
 * Digital, PWM			D45		45
 * Digital, PWM			D46		46
 * Digital				D47		47
 * Digital				D48		48
 * Digital				D49		49
 * Digital, MISO		D50		50
 * Digital, MOSI		D51		51
 * Digital, SCK			D52		52
 * Digital, SS			D53		53
 *
 * Digital, SCL, RX		SCL		21
 * Digital, SDA, TX		SDA		20
 * Digital, Serial R1	SR1		19
 * Digital, Serial T1	ST1		18
 * Digital, Serial R2	SR2		17
 * Digital, Serial T2	ST2		16
 * Digital, Serial R3	SR3		15
 * Digital, Serial T3	ST3		14
 *
 * Digital, Serial R0	SR0		0
 * Digital, Serial T0	ST0		1
 * Digital, PWM			D2		2
 * Digital, PWM			D3		3
 * Digital, PWM			D4		4
 * Digital, PWM			D5		5
 * Digital, PWM			D6		6
 * Digital, PWM			D7		7
 * Digital, PWM			D8		8
 * Digital, PWM			D9		9
 * Digital, PWM			D10		10
 * Digital, PWM			D11		11
 * Digital, PWM			D12		12
 * Digital, PWM			D13		13
 */

/*
 * Pinouts in Use:
 */
//Define constants
#define ROBOT_LENGTH 30
#define ROBOT_WIDTH 20
#define ARENA_WIDTH 224

// Initialise variables
coord homeCoord;                    // Stores the robot's starting position
coord position;                     // Stores the robot's position
float compassOffset = 0;            // Offset to account for initial bearing from North
float xOrientation = 0;             // Indicates whether robot should face +ve or -ve x-direction
rectangle arena;                    // Defines edges of arena to locate the robot
rectangle dangerZone;               // Defines edges of safe zone for mine disposal and movement onto the next course
vector<coord> dangerousMineCoords;  // Holds co-ordinates of dangerous mines
vector<coord> path;                 // Container for current path to be followed
vector<coord> safeMineCoords;       // Holds co-ordinates of safe mines
vector<rectangle> forbiddenZones;    // Holds rectangle objects that denote areas considered off-limits due to the presence of dangerous mines

// Initialise inputs
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified();    // Initialise mag compass object
compass compass(mag);                                               // Put mag compass into compass container object

ldr LDR00(A0);  // Initialise LDR objects
ldr LDR01(A1);
ldr LDR02(A2);
ldr LDR03(A3);
ldr LDR07(A7);
ldr LDR08(A8);
ldr LDR09(A9);
ldr LDR10(A10);
ldr LDR11(A11);

NewPing initXUltrasound(10, 11);            // Initialise US objects
NewPing initYUltrasound(12, 13);            //Should be mounted on the side
ultrasound xUltrasound(initXUltrasound);    // Put US objects into container objects
ultrasound yUltrasound(initYUltrasound);

// Initialise outputs
led green(3, 1);    // Assign LED ports
led red(4);
led yellow(5);

Adafruit_MotorShield motorShield = Adafruit_MotorShield();      // Initialise motor shield object
motor leftMotor(3);                                             // Motor on port 1 and initial speed 0 (default third parameter)    
motor rightMotor(4);                                            // Motor on port 2 and initial speed 0 (default third parameter)

Servo arm;  // Create servo arm object


void setup () {
  //Initialise serial sample rate
  Serial.begin(9600);
  delay(1000);
 
  // Initialise motor shield and motors
  motorShield.begin();
  leftMotor.assignedMotorShield = motorShield;
  rightMotor.assignedMotorShield = motorShield;
  leftMotor.init();
  rightMotor.init();

  // Initialise servo
  arm.attach(10);
  arm.write(30);

  // Initialise compass
  compass.init();
  compass.xFluxCorrection = 2.77;
  compass.yFluxCorrection = -46.81;

}
