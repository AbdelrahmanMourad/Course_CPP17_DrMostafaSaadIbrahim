/**
	----------------------------------------------------------------------
	Homework:
	---------

		----------------
		Lecture (05-02):
		----------------

			-------------
			Question (1):
			-------------


	----------------------------------------------------------------------
**/

// Include Library.
#include <iostream>
using namespace std;

// Driving Code (Entry Point)
int main()
{
	// Variable Declarations.
	int a, b;

	// ++a: prefix increment: increment then assign
	a = 10;						   // Assignation.
	b = ++a;					   // Prefix.
	cout << a << " " << b << "\n"; // 11 11

	a = 10;				 // Assignation.
	cout << ++a << "\n"; // 11

	// a++: postfix increment: assign then increment
	a = 10;						   // Assignation.
	b = a++;					   // Postfix.
	cout << a << " " << b << "\n"; // 11 10

	a = 10;
	cout << a++ << "\n"; // 10

	a = 10;
	cout << (a++) << "\n"; // 10

	a = 10;
	cout << a++ + ++a << "\n"; // undefined

	return 0;
}
