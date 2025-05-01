/**
    ----------------------------------------------------------------------
    Homework #2:
    -----------
        Write Code To Print Triangle.
            *
            * *
            * * *
            * * * *
            * * * * *
    ----------------------------------------------------------------------
**/

// Library Include.
#include <iostream>
using namespace std;

// Driving Code.
int main()
{
    // Method 1 Manually.
    cout << "*\n"
         << "* *\n"
         << "* * *\n"
         << "* * * *\n"
         << "* * * * *\n";

    int NUMBER_OF_LAYERS;
    cout << "Enter Number of Pyramids Layers.";
    cin >> NUMBER_OF_LAYERS;

    // Method 2 Using Loops
    for (auto row = 1; row <= NUMBER_OF_LAYERS; row++)
    {
        for (auto column = 1; column <= row; column++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}