#include<iostream>
#include<cmath>
using namespace std;

class coord {
         public:
                 int x, y;
		 coord(int inputX = 0, int inputY = 0) {
                        /* Constructor, can use:
                         * coord newCoord(100, 12);
                         * to create a constructor
                         */
                        x = inputX;
                        y = inputY;
                }
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
                        if ( (inputCoord.x > x0 && inputCoord.x < x1) && (inputCoord.y > y0 && inputCoord.y < y1) ) {
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

int main() {

	/*
	coord testCoord;
	testCoord.x = 10; testCoord.y = 20;
	cout << testCoord.x << ", " << testCoord.y << "\n";

	coord testAdd;
	testAdd.x = 1; testAdd.y = 2;
	testCoord = testCoord.add(testAdd);
	cout << testCoord.x << ", " << testCoord.y << "\n";

	coord testSub;
	testSub.x = 100; testSub.y = 5;
	testCoord = testCoord.subtract(testSub);
	cout << testCoord.x << ", " << testCoord.y << "\n";

	coord testDist;
	testDist.x = 1; testDist.y = 2;
	cout << testCoord.distance(testDist) << "\n";

	rectangle testRect;
	testRect.x0 = 1; testRect.x1 = 3;
	testRect.y0 = 5; testRect.y1 = 7;
	testRect.init();

	cout << testRect.a.x << ", " << testRect.a.y << "\n";

	testCoord.x = 10; testCoord.y = 10;

	coord corner = testRect.nearestCorner(testCoord);
	cout << corner.x << ", " << corner.y << "\n";

	testCoord.x = 2; testCoord.y = 6;
	cout << testRect.insideRectangle(testCoord) << "\n";

	testCoord.x = 20; testCoord.y = 6;
	cout << testRect.insideRectangle(testCoord) << "\n";
	*/

	coord newCoord(100, 12);
	cout << newCoord.x << ", " << newCoord.y << "\n";
}
