/**
	----------------------------------------------------------------------
	Homework #3:
	------------
		* We know we will read 8 numbers
		* 	The first number is the first odd
		* 	The third number is the second odd
		* 	The fifth number is the their odd
		* 	The seventh number is the forth odd
		*
		* The same logic for even numbers
		*
		* The key: good naming variables and read them in right order
	----------------------------------------------------------------------
**/
#include <iostream>
using namespace std;

int main()
{
	// Variables Declaration.
	int even1, even2, even3, even4;
	int odd1, odd2, odd3, odd4;

	// Taking User Inputs.
	cin >> odd1 >> even1;
	cin >> odd2 >> even2;
	cin >> odd3 >> even3;
	cin >> odd4 >> even4;

	// Sum Operations.
	int even_sum = even1 + even2 + even3 + even4;
	int odd_sum = odd1 + odd2 + odd3 + odd4;

	// Display User Outputs.
	cout << even_sum << " " << odd_sum << "\n";

	return 0;

	// Testing The Repo On the Work-Laptop
	// Testing The Repo On the Work-Laptop from bash
	
}
