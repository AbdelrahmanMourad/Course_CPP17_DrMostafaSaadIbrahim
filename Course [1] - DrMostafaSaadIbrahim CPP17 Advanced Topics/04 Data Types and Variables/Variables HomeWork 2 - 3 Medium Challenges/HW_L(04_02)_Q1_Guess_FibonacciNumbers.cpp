/**
    ----------------------------------------------------------------------
    Homework #1:
    ------------
        Calculate and Print Fibonacci Numbers.
    ----------------------------------------------------------------------
**/

#include <iostream>
using namespace std;

// Function ProtoType.
int FibonacciNumbers(int n);

int main()
{
    // Variable Declaration.
    int num1, num2, num3;

    // Fibonacci Number Calculations, and Print.
    num1 = 0, num2 = 1, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";
    num1 = num2, num2 = num3, num3 = num1 + num2, cout << num3 << "\n";

    // https://en.wikipedia.org/wiki/Fibonacci_number

    return 0;
}

// Function Implementation.
int FibonacciNumbers(int n)
{
    int Num1 = 0, Num2 = 1, Num3 = Num1 + Num2;
    for (int i = 0; i <= n; i++)
    {
        Num1 = Num2;
        Num2 = Num3;
        Num3 = Num1 + Num2;
    }
}