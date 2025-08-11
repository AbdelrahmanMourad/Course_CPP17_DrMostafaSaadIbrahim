/*
=================================================================================================
SUMMARY: stack
=================================================================================================
    Stack
        ● Imagine a box and you put book by book.

=================================================================================================
*/

/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_STACK_H
#define MY_STACK_H

/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <stack>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
/*_________________Private_Functions_________________*/
namespace private_pair_helping_funcations
{
    void stack_print(std::stack<std::string> &S);
};

/*_________________Public_Functions_________________*/
namespace namespace_tuple
{
    void main1_Declaraions_Operations(void);
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
/*_________________Private_Functions_________________*/
void private_pair_helping_funcations::stack_print(std::stack<std::string> &S)
{
    std::cout << "Stack elements: ";
    while (!S.empty())
    {
        std::cout << S.top() << " ";
        S.pop();
    }
    std::cout << std::endl;
}

/*_________________Public_Functions_________________*/
void namespace_tuple::main1_Declaraions_Operations(void)
{
    std::stack<std::string> stack_string;
    stack_string.push("Ibrahim");
    stack_string.push("Mourad");
    stack_string.push("Abdelrahman");

    private_pair_helping_funcations::stack_print(stack_string); // Abdelrahman Mourad Ibrahim
}
/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*STACK_H*/
