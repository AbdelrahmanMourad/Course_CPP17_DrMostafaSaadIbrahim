/*
=================================================================================================
SUMMARY: pair
=================================================================================================
    Pair
        ● It's just a container of 2 data types.
            ○ You declare it as this: {"""std::pair<int, double> P1"""}
            ○ to fill it use this function {""P1=std::make_pair(first_val , second_val)""}
            ○ To access them:
                - {""P1.first""}
                - {""P1.second""}
            ○ No need to include any specific library.

=================================================================================================
*/

/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_PAIR_H
#define MY_PAIR_H

/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <stack>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
namespace namespace_pair
{
    void main1_Declaraions_Operations(void);
    void main2_Pair_Comparison(void);

    void print_stack_of_pair_of_pair(std::stack<std::pair<int, std::pair<std::string, int>>> Temp_Stack)
    {
        while (!Temp_Stack.empty())
        {
            std::cout << "Stach.top().first" << Temp_Stack.top().first << "\n"
                      << "Stach.top().second.first" << Temp_Stack.top().second.first << "\n"
                      << "Stach.top().second.second" << Temp_Stack.top().second.second << "\n\n";

            Temp_Stack.pop();
        }
    }
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
/*_________________Public_Functions_________________*/
void namespace_pair::main1_Declaraions_Operations(void)
{
    std::pair<int, std::string> pair1 = std::make_pair(10, "Abdelrahman");
    std::cout << "pair1.first= " << pair1.first << "\t,pair1.secone= " << pair1.second << "\n";

    std::stack<std::pair<int, std::string>> stack1;
    stack1.push(pair1);
    stack1.push(pair1);
    stack1.push(pair1);

    std::pair<int, std::pair<int, std::string>> my_pair2 = std::make_pair(10, std::make_pair(20, "Mourad"));
    my_pair2 = std::make_pair(10, pair1);
}
void main2_Pair_Comparison(void)
{
    /*
    ----------------------------------------------------------------------
    Pair: Comparison
    ----------------------------------------------------------------------
        ● Let’s say we have pair<int, pair<string, int> >
            ○ P1 = (10, (mostafa, 35))
            ○ P2 = (7, (ali, 15))
            ○ P3 = (10, (ziad, 17))
            ○ P4 = (10, (mostafa, 20))
        ● Comparing pair order on first element, then on second element
    ----------------------------------------------------------------------
    */
    std::stack<std::pair<int, std::pair<std::string, int>>> MyStack1;
    MyStack1.push(std::make_pair(10, std::make_pair("Mostafa", 35))); //  P1 = (10, (mostafa, 35))
    MyStack1.push(std::make_pair(07, std::make_pair("Ali", 15)));     //  P2 = (7, (ali, 15))
    MyStack1.push(std::make_pair(10, std::make_pair("Ziad", 17)));    //  P3 = (10, (ziad, 17))
    MyStack1.push(std::make_pair(10, std::make_pair("Mostafa", 20))); //  P4 = (10, (mostafa, 20))

    // Print using function.
    namespace_pair::print_stack_of_pair_of_pair(MyStack1);

    // Print here.
    while (!MyStack1.empty())
    {
        std::cout << "Stach.top().first" << MyStack1.top().first << "\n"
                  << "Stach.top().second.first" << MyStack1.top().second.first << "\n"
                  << "Stach.top().second.second" << MyStack1.top().second.second << "\n";

        MyStack1.pop();
    }
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*PAIR_H*/
