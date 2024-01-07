/**
	----------------------------------------------------------------------
	Homework #1:
	------------

	----------------------------------------------------------------------
**/

// Include Library.
#include <iostream>
using namespace std;

int main()
{
	// Variable Initialization. (Declaration + Assignation)
	// 		=>	x{6}; == x=6;
	int x{6}, y{3};

	// Print Outputs
	cout << x + y << "\n";		   // Sum = x+y = 9
	cout << x + 2 * y - 1 << "\n"; // x + (2*y) -1 = 6 + (2*3) -1 = 11
	cout << x / y << "\n";		   // 2

	// Variable Initialization.
	// 		=>	(int z1 {---}) == (int z1 = (---))
	int z1{(x + y) / 3 / 3}; // z1 = ((6+3) /3 /3) = 1

	cout << z1 << "\n";	// 1
	
	return 0;
}