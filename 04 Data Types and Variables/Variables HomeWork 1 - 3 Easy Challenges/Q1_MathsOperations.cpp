/**
    ----------------------------------------------------------------------
    Homework #1:
    ------------
        Take Two Inputs from user and return maths operations of them.
    ----------------------------------------------------------------------
**/

#include <iostream>
using namespace std;

int main()
{
    // Declare Variables.
    double a, b;

    // Take Input Values From User.
    cin >> a >> b;

    // Display Outputs.
    cout << a << "+" << b << "=" << a + b << "\n";
    cout << a << "-" << b << "=" << a - b << "\n";
    cout << a << "/" << b << "=" << a / b << "\n";
    cout << a << "*" << b << "=" << a * b << "\n";

    return 0;
}