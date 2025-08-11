/*
=================================================================================================
SUMMARY: deque
=================================================================================================
    Deque
        ● This one is almost like one we implemented before
            ○ Add front     = push_front()
            ○ Add end       = push_back()
            ○ Get front     = front()
            ○ Get back      = back()
            ○ Remove front  = pop_front()
            ○ Remove back   = pop_back()
            ○ size()        = How many elements?
            ○ empty()       = any more elements
        ● Logic and printing
            ○ Decide where to add elements
            ○ You can print in the 2 directions
            ○ Very flexible data structure
        ● Note:
            ○ we can index deuqu like array: Q[i]
            ○ we can index deque using Q.at(i) ... better handling out of ranges with exceptions.
            ○ we can use Q.size() for max index.

=================================================================================================
*/

/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_DEQUE_H
#define MY_DEQUE_H

/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <deque>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
/*_________________Public_Functions_________________*/
namespace namespace_deque
{
    void main1_Declaraions_Operations(void);
    void main2_Print_Queue(void);
    void main3_is_parlindrome(void);
};
/*_________________Private_Functions_________________*/
namespace private_deque_helping_funcations
{
    void deque_print_back(std::deque<int> &dQ);
    void deque_print_front(std::deque<int> &dQ);
    bool deque_is_palindrome(std::string &&str);
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
/*_________________Public_Functions_________________*/
void namespace_deque::main1_Declaraions_Operations(void)
{
    std::deque<int> dQ1{11, 10, 20, 30, 40, 50, 60, 70}; // Direct initialization.
    std::deque<int> dQ2;                                 // Declaration without initialization.
    dQ2.push_back(2);                                    // {2}
    dQ2.push_back(3);                                    // {2, 3}
    dQ2.push_back(4);                                    // {2, 3, 4}
    dQ2.push_back(5);                                    // {1, 2, 3, 4, 5}
    dQ2.push_front(1);                                   // {1, 2, 3, 4}
    dQ2.push_front(0);                                   // {0, 1, 2, 3, 4, 5}

    // Construct new deques from the old ones
    std::deque<int> dQ_Copy1{dQ1};
    std::deque<int> dQ_Copy2 = dQ2;

    // print deque.
    private_deque_helping_funcations::deque_print_back(dQ_Copy1);
    private_deque_helping_funcations::deque_print_front(dQ_Copy2);

    // size & clear:
    std::cout << "dequeue_copy2.size()= " << dQ_Copy2.size() << "\t,Before: \"Copy2.clear()\"\n";
    dQ_Copy2.clear();
    std::cout << "dequeue_copy2.size()= " << dQ_Copy2.size() << "\t,After:  \"Copy2.clear()\"\n";
}
void namespace_deque::main2_Print_Queue(void)
{
    std::deque<int> dQ1{11, 10, 20, 30, 40, 50, 60, 70}; // Direct initialization.
    std::deque<int> dQ2 = {0, 1, 2, 3, 4, 5};            // Declaration without initialization.

    // Construct new deques from the old ones
    std::deque<int> dQ_Copy1{dQ1};
    std::deque<int> dQ_Copy2 = dQ2;

    // print deque.
    private_deque_helping_funcations::deque_print_back(dQ_Copy1);
    private_deque_helping_funcations::deque_print_front(dQ_Copy2);

    // print deque.
    for (int i = 0; i < dQ_Copy1.size(); i++) // Normal for loop.
        std::cout << dQ_Copy1.at(i) /*==Copy1[i]*/ << " ";
    std::cout << "\n";

    for (const auto &elem : dQ_Copy2) // Range-based for loop.
        std::cout << elem << " ";
    std::cout << "\n";

    // print deque specific element.
    std::cout << "deQue[1]" << dQ_Copy1[1] << "\n";
    std::cout << "deQue.at(1)" << dQ_Copy1.at(1) << "\n";
}
void namespace_deque::main3_is_parlindrome(void)
{
    std::cout << "is_palindrome(\"abba\")=  " << private_deque_helping_funcations::deque_is_palindrome("abba") << "\n"  /*true*/
              << "is_palindrome(\"abcba\")= " << private_deque_helping_funcations::deque_is_palindrome("abcba") << "\n" /*true*/
              << "is_palindrome(\"xxy\")=   " << private_deque_helping_funcations::deque_is_palindrome("xxy") << "\n";  /*false*/
}

/*_________________Private_Functions_________________*/
void private_deque_helping_funcations::deque_print_back(std::deque<int> &Q)
{
    std::cout << "Queue elements (back 2 front): \n";
    while (!Q.empty())
    {
        std::cout << Q.back() << " ";
        Q.pop_back();
    }
    std::cout << std::endl;
}
void private_deque_helping_funcations::deque_print_front(std::deque<int> &Q)
{
    std::cout << "Queue elements (front 2 back): \n";
    while (!Q.empty())
    {
        std::cout << Q.front() << " ";
        Q.pop_front();
    }
    std::cout << std::endl;
}
bool private_deque_helping_funcations::deque_is_palindrome(std::string &&str)
{
    std::deque<int> dq;

    for (char c : str) // Add chars.
        dq.push_back(c);

    while (dq.size() > 1)
    {
        char f = dq.front();
        dq.pop_front();

        char b = dq.back();
        dq.pop_back();

        if (f != b)
            return false;
    }
    return true;
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*DEQUE_H*/
