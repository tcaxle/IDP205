#include<iostream>
#include<cmath>
using namespace std;

class coord {
         public:
                 int x, y;
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

int main() {
	coord testCoord;
	testCoord.x = 10;
	testCoord.y = 20;
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
}
