/**
    ----------------------------------------------------------------------
    Homework #1:
    ------------
        Calculate and Print Fibonacci Numbers.
            // https://en.wikipedia.org/wiki/Fibonacci_number
    ----------------------------------------------------------------------
**/

#include <iostream>
using namespace std;

// Function ProtoType.
int get_FibonacciNumbers(int n);
void PrintFibonacciNumbers_static(void);

int main()
{
    int Fib = get_FibonacciNumbers(12);

    return 0;
}

void PrintFibonacciNumbers_static(void)
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
}

// Function Implementation.
int get_FibonacciNumbers(int n)
{
    int Num1 = 0, Num2 = 1, Num3 = 2;
    cout << "Fib(1)= \t" << Num1 << "\n"
         << "Fib(2)= \t" << Num2 << "\n"
         << "Fib(3)= \t" << Num3 << "\n";
    for (int i = 0; i <= n; i++)
    {
        Num1 = Num2;
        Num2 = Num3;
        Num3 = Num1 + Num2;
        cout << "Fib(" << 4 + i << ")= \t" << Num3 << "\n";
    }
}