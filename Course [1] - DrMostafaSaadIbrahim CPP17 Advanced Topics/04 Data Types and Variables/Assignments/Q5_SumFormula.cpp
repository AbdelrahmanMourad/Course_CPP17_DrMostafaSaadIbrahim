    /**
    ----------------------------------------------------------------------
    Homework #2:
    ------------
        * The sum of numbers from 1 to E is known as: (E * (E+1)) / 2
        *
        * Now, we need to get the sum from S to E
        *
        * Assume we want to get the sum from 5 to 9
        *
        * Simple idea:
        * Sum 1 to 9	:   1 2 3 4 5 6 7 8 9
        * Sum 1 to 5-1	:   1 2 3 4
        *
        * Now subtract these two summations: 5 6 7 8 9
    ----------------------------------------------------------------------
**/
#include <iostream>

using namespace std;

int main()
{
    // User Message.
    cout << "Enter 2 numbers: start and end: ";
    // Declare Variables.
    int start, end;
    // Take User Input.
    cin >> start >> end;
    // Algorithm Formula.
    int sumEnd = (end * (end + 1)) / 2;
    // Algorithm on the next start.
    int startBefore = start - 1;
    int sumStartBefore = (startBefore * (startBefore + 1)) / 2;
    // Sum.
    int sumRange = sumEnd - sumStartBefore;
    // Display User Outputs.
    cout << "Sum of numbers from 1 to " << end << " = " << sumEnd << "\n";
    cout << "Sum of numbers from " << start << " to " << end << " = " << sumRange;
    return 0;
}
