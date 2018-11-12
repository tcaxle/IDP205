/*
 * firmware.h
 *
 *  Created on: 7 Nov 2018
 *      Author: tom
 *
 *  For the creation of an interface between electronic
 *  (Arduino Mega) and software for greater versatility
 */

// Preamble
#include "classes.h"

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
 * Analog	 			A7		61
 *
 * Analog 				A8		62
 * Analog 				A9		63
 * Analog 				A10		64
 * Analog 				A11		65
 * Analog 				A12		66
 * Analog				A13		67
 * Analog				A14		68
 * Analog				A15		69
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

// Declare a Motor Shield and Motor
Adafruit_MotorShield motorShield = Adafruit_MotorShield();
motor leftMotor;

void setup () {
  motorShield.begin();
  leftMotor.assignedMotorShield = motorShield;
  leftMotor.port = 1;
  leftMotor.init();
}


