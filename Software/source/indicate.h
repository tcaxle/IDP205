/*
 * indicate.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * contains functions for controlling LEDs (or other output indicators)
 */

// ** Preamble ** //
#include "firmware.h"

// **** PUBLIC **** //

// ** LED Control ** //

void ledNone() {
	// Turns on green LED only
	// For indication of no mine detected
}

void ledDang() {
	// Turns on red LED only
	// For indication of dangerous mine detected
}

void ledSafe() {
	// Turns on yellow LED only
	// For indication of safe mine detected
}

void ledPanic() {
	// Turns on all LEDs to indicate panic mode
}

void ledHappy() {
	// Flashes LEDs to celebrate victory
}

// **** PRIVATE **** //
