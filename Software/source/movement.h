/*
 * movement.h
 *
 * Created: 10/11/2018
 * Author: T. Crossley
 *
 * Contains algorithms for moving the robot
 */

// ** Preamble ** //
#include "orientation.h"

// **** PUBLIC **** //

// ** Facing ** //

void faceFwd() {
	// Points the robot forward relative to its course
}

void faceBwd() {
	// Points the robot backward relative to its course
}

void faceLft() {
	// Points the robot left relative to its course
}

void faceRgt() {
	// Points he robot right relative to its course
}

void faceXFwd() {
	// Points the robot in the positive X direction
}

void faceXBwd() {
	// Points the robot in the negative X direction
}

void faceYFwd() {
	// Points the robot in the positive Y direction
}

void faceYBwd() {
	// Points the robot in the negative Y direction
}

void faceCoord(coord input_coord) {
	// Points the robot towards the coordinate "input_coord"
}

// ** Movement ** //

void moveFwd(float input_distance) {
	// Moves the robot forward (relative to current facing) by distance "input_distance"
}

void moveBwd(float input_distance) {
	// Moved the robot backward (relative to current facing) byb distance "input_distance"
}

// ** Rotation ** //

void spinLft(float input_degrees) {
	// Rotates the robot left (anticlockwise) through angle "input_degrees"
}

void spinRgt(float input_degrees) {
	// Rotates the robot right (clockwise) through angle "input_degrees"
}

// ** Path ** //

void pathFollow(float input_distance) {
	// Moves the robot forwards along the path by distance "input_distance"
}

void pathEdge() {
	// Moves the robot to the edge of the search area via the shortest route, avoiding mines
}

void pathReturn() {
	// Moves the robot back to the point on its path where it left off, avoiding mines
}

void pathHome() {
	// Moves the robot back to the startbox via the shortest route, avoiding mines
}

void pathGo(coord input_coord) {
	// Moves the robot to the coordinate "input_coord" via the shortest route, avoiding mines
}

// ** Panic ** //

void panicHome() {
	// Moves the robot back to the start box, regardless of mines in the way
}

void panicEdge() {
	// Moves the to the nearest edge, regardless of mines in the way
}

void panicRun() {
	// Moves the robot in a straight line, regardless of mines, until it reaches the edge
}

void panicPanic() {
	// Moves eratically and without direction in an inescapable loop (edgecase)
}

// **** PRIVATE **** //
