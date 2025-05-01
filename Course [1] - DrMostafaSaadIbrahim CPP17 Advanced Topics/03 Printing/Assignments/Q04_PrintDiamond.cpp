/**
    ----------------------------------------------------------------------
    Homework #2:
    -----------
        Write Code To Print a Diamond.
                 *
               * * *
             * * * * *
           * * * * * * *
             * * * * *
               * * *
                 *
    ----------------------------------------------------------------------
**/

// Library Include.
#include <iostream>
using namespace std;

// Functions Prototypes.
int get_numberOFLayers(void);
void PrintDiamond_Manually(void);
void PrintDiamond_c_Style(int NUMBER_OF_LAYERS);
void printDiamond_cpp_style(int max);

// Entry Point.
int main()
{
  
  int max = get_numberOFLayers();

  return 0;
}

int get_numberOFLayers(void)
{
  // Getting User Input.
  // int NUMBER_OF_LAYERS;
  // cout << "Enter Number of Pyramids Layers.";
  // cin >> NUMBER_OF_LAYERS;
  int NUMBER_OF_LAYERS = 5;

  return NUMBER_OF_LAYERS;
}

void PrintDiamond_Manually(void)
{
  //_________________________Method 1 Manually__________________________
  cout << "      *\n"       //  |    " " =6    |    "* " =1    |
       << "    * * *\n"     //  |    " " =4    |    "* " =3    |
       << "  * * * * *\n"   //  |    " " =2    |    "* " =5    |
       << "* * * * * * *\n" //  |    " " =0    |    "* " =7    |
       << "  * * * * *\n"   //  |    " " =2    |    "* " =5    |
       << "    * * * \n"    //  |    " " =4    |    "* " =3    |
       << "      *\n";      //  |    " " =6    |    "* " =1    |

 
}
void printDiamond_cpp_style(int max)
{
   //_______________________Method 2 Using Loops______________________________
  // Upper part of the diamond
  for (int row = 1; row <= max; row += 2)
  {
    // Uses std::string(count, char) to easily generate spaces and stars.
    std::cout << std::string((max - row), ' ');

    for (int j = 0; j < row; j++)
    {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }

  // Lower part of the diamond
  for (int row = max - 2; row >= 1; row -= 2)
  {
    // Uses std::string(count, char) to easily generate spaces and stars.
    std::cout << std::string((max - row), ' ');

    for (int j = row; j > 0; j--)
    {
      std::cout << "* ";
    }
    std::cout << std::endl;
  }
}

void PrintDiamond_c_Style(int NUMBER_OF_LAYERS)
{
 //_______________________Method 2 Using Loops______________________________
  // Print Upper Pyramid.
  for (auto row = 0; row <= NUMBER_OF_LAYERS; row += 2) // Loop on layers top-down from (1) to (Max)
  {
    std::cout << std::string((NUMBER_OF_LAYERS - row), ' ');
    // for (auto column_Space = NUMBER_OF_LAYERS -row; column_Space >= 0; column_Space--) // Print Spaces from (Max-Row) to (0)
    // {
    //   std::cout << " ";
    // }

    for (auto column_stars = 0; column_stars <= row; column_stars++) // Print Stars from (1) to (row number).
    {
      std::cout << "* ";
    }
    std::cout << std::endl; // New Line To Next Row.
  }

  // Print Lower Pyramid.
  for (auto row = NUMBER_OF_LAYERS; row >= 1; row -= 2) // Loop on layers top-down from (Max) to (1)
  {
    for (auto column_Space = 0; column_Space <= NUMBER_OF_LAYERS - row; column_Space++) // Print Spaces from (0) to (Max-Row)
    {
      std::cout << " ";
    }
    for (auto column_stars = row; column_stars >= 1; column_stars--) // Print Stars from (row number) to (1)
    {
      std::cout << "* ";
    }
    std::cout << std::endl; // New Line To Next Row.
  }
}