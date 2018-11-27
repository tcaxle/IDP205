/*
 * indicate.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * contains functions for controlling LEDs (or other output indicators)
 */

// ** Preamble ** //

// **** PUBLIC **** //

// ** LED Control ** //

void ledNone() {
	// Turns on green LED only
	// For indication of no mine detected
  green.set(1);
  red.set(0);
  yellow.set(0);
}

void ledDang() {
	// Turns on red LED only
	// For indication of dangerous mine detected
  green.set(0);
  red.set(1);
  yellow.set(0);
}

void ledSafe() {
	// Turns on yellow LED only
	// For indication of safe mine detected
  green.set(10);
  red.set(0);
  yellow.set(1);
}

void ledPanic() {
	// Turns on all LEDs to indicate panic mode
}

void ledHappy() {
	// Flashes LEDs to celebrate victory
}

// **** PRIVATE **** //
