/**
    ----------------------------------------------------------------------
    Homework #2:
    -----------
        Write Code To Print a Pyramid.
                 *
               * * *
              * * * *
             * * * * *
            * * * * * *
    ----------------------------------------------------------------------
**/

// Library Include.
#include <iostream>
using namespace std;

//______________________Functions_Prototypes______________________
void PrintPyramid_Manually(void);
void PrintPyramid(int NUMBER_OF_LAYERS);

//_______________________Entry_Point_______________________
int main()
{
    int max = 5;

    return 0;
}


//________________________Functions_Implementation________________________
void PrintPyramid_Manually(void)
{
    // Method 1 Manually.
    cout << "    *\n"
         << "   * *\n"
         << "  * * *\n"
         << " * * * *\n"
         << "* * * * *\n";
}

void PrintPyramid(int NUMBER_OF_LAYERS)
{
    // Method 2 Using Loops.
    for (auto row = 1; row <= NUMBER_OF_LAYERS; row++) // Loop on layers top-down from 1 to Max
    {
        for (auto column_Space = NUMBER_OF_LAYERS - row; column_Space >= 0; column_Space--) // Print Spaces from (Max-Row) to (0)
        {
            std::cout << " ";
        }
        for (auto column_stars = 1; column_stars <= row; column_stars++) // Print Stars from (1) to (row number).
        {
            std::cout << "* ";
        }
        std::cout << std::endl; // New Line To Next Row.
    }
}