/*
=================================================================================================
SUMMARY: STL Iterators
=================================================================================================

-------------------------------------------------------------------------------------------------
Recall printing Deque
-------------------------------------------------------------------------------------------------
        ● We can print forward or backward: e.g. .front, .pop_front
        ● But I don’t want it to be freed?
            ○ Ok Don’t use &. Make a copy
            ○ But this is waste of time and memory?
            ○ Ok Use iterators
                --------------------------------------------------------
                |   void print_front (std::deque<int> &dq)             |
                |   {                                                  |
                |       std::cout << "Queue elements (front): ";       |
                |                                                      |
                |       while (! dq.empty())                           |
                |       {                                              |
                |           std::cout << dq.front() << " ";            |
                |           dq.pop_front();                            |
                |       }                                              |
                |       std::cout << "\n";                             |
                |   }                                                  |
                |------------------------------------------------------|
                |   #include <deque>                                   |
                |------------------------------------------------------|
                |   int main()                                         |
                |   {                                                  |
                |       std::deque <int> dQ {1, 2, 3, 4, 5};           |
                |       print_front ( dQ );                            |
                |   }                                                  |
                --------------------------------------------------------

-------------------------------------------------------------------------------------------------
Iterators
-------------------------------------------------------------------------------------------------
    ● Iterator is an object, but think of it like a position in an array
        ○ begin() = first element
        ○ end() = AFTER last element
    ● Moving forward/backward: use ++pos, --pos
    ● Want the current value? *pos
        ○ You can print / change

            ---------------------------------------------------------------------------------
            |  ___________            ___________             ___________                   |
            | |  begin()  | ==(++)=> |    Pos    | ==(++)==> |   end()   |                  |
            | |____    ___|          |____    ___|           |____    ___|                  |
            |      \  /                   \  /                    \  /                      |
            |       \/                     \/                      \/                       |
            |    |-----|     |-----|     |-----|     |-----|     |-----|                    |
            |    |     | ==> |     | ==> |     | ==> |     | ==> |     |                    |
            |    |  1  |     |  2  |     |  3  |     |  4  |     |  5  |                    |
            |    |     | <== |     | <== |     | <== |     | <== |     |                    |
            |    |-----|     |-----|     |-----|     |-----|     |-----|                    |
            |                                                                               |
            ---------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------
Using iterators: Iterate forward
-------------------------------------------------------------------------------------------------
     ● deque<int>::iterator it
        ○ It is an object of type iterator
        ○ But specifically deque iterator
    ● We can deal with it with ++ and -
    ● *it = value
        ○ Called dereference operator
    ● q.begin() is pointing to the begin
    ● Are we done iterating?
        ○ q.end() = AFTER the content
        ○ So we can use that to know we are done
                |---------------------------------------------------------------|
                |   void print_front (std::deque<int> &dq)                      |
                |   {                                                           |
                |       // Declare iterator to deque, init with 1st element.    |
                |       std::deque<int>::iterator it = dq.begin();              |
                |                                                               |
                |       std::cout << "Queue elements (front): ";                |
                |                                                               |
                |       while (it != dq.end() )                                 |
                |       {                                                       |
                |           std::cout << it* << " ";                            |
                |           ++it;                                               |
                |       }                                                       |
                |       std::cout << "\n";                                      |
                |   }                                                           |
                |---------------------------------------------------------------|
                |   #include <iterator>                                         |
                |   #include <deque>                                            |
                |---------------------------------------------------------------|
                |   int main()                                                  |
                |   {                                                           |
                |       std::deque <int> dQ {1, 2, 3, 4, 5};                    |
                |       print_front ( dQ );                                     |
                |   }                                                           |
                |---------------------------------------------------------------|


=================================================================================================
*/

/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_TUPLE_H
#define MY_TUPLE_H

/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <iterator>
#include <deque>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
namespace namespace_STL_Iterators
{
    /*_________________Public_Functions_________________*/
    void main1_print_deque_using_iterators(void);
};
namespace private_iterators_helping_fn
{
    /*_________________Private_Functions_________________*/
    void print_deque_normal_front_while(std::deque<int> dQ);
    void print_deque_normal_back_while(std::deque<int> dQ);
    void print_deque_iterator_front_while(std::deque<int> &dQ);
    void print_deque_iterator_front_for(std::deque<int> &dQ);
    void print_deque_iterator_back_while(std::deque<int> &dQ);
    void print_deque_iterator_back_for(std::deque<int> &dQ);
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
/*_________________Public_Functions_________________*/
void namespace_STL_Iterators::main1_print_deque_using_iterators(void)
{
    std::deque<int> dQ{1, 2, 3, 4, 5};
    private_iterators_helping_fn::print_deque_normal_front_while(dQ);   // 1, 2, 3, 4, 5
    private_iterators_helping_fn::print_deque_iterator_front_while(dQ); // 1, 2, 3, 4, 5
    private_iterators_helping_fn::print_deque_iterator_front_for(dQ);   // 1, 2, 3, 4, 5
    private_iterators_helping_fn::print_deque_normal_back_while(dQ);    // 5, 4, 3, 2, 1
    private_iterators_helping_fn::print_deque_iterator_back_while(dQ);  // 5, 4, 3, 2, 1
    private_iterators_helping_fn::print_deque_iterator_back_for(dQ);    // 5, 4, 3, 2, 1
}

/*_________________Private_Functions_________________*/
void private_iterators_helping_fn::print_deque_normal_front_while(std::deque<int> dQ)
{
    std::cout << "print_deque_normal_front_while\n"
              << "DeQue Elements:\t";
    while (!dQ.empty())
    {
        /*
        -------------------------------------------------------------------------
        %deque.front()
        ---------------
        Returns a read/write reference to the data at the first element of the %deque.

        -------------------------------------------------------------------------
        %deque.pop_front()
        ---------------
        Removes first element.
        This is a typical stack operation. It shrinks the %deque by one.
        Note that no data is returned, and if the first element's data is needed,
            it should be retrieved before pop_front() is called.
        -------------------------------------------------------------------------
        */
        std::cout << dQ.front() << " "; // read 1st element in the %deue.
        dQ.pop_front();                 // remove 1st element in the %deque.
    }
    std::cout << std::endl;
}
void private_iterators_helping_fn::print_deque_normal_back_while(std::deque<int> dQ)
{
    std::cout << "print_deque_normal_back_while\n"
              << "DeQue Elements:\t";
    while (!dQ.empty())
    {
        /*
        -------------------------------------------------------------------------
        %deque.back()
        -------------
        Returns a read/write reference to the data at the last element of the %deque.

        -------------------------------------------------------------------------
        %deque.pop_back()
        -----------------
        Removes last element.
        This is a typical stack operation. It shrinks the %deque by one.
        Note that no data is returned, and if the last element's data is needed,
            it should be retrieved before pop_back() is called.
        -------------------------------------------------------------------------
        */
        std::cout << dQ.back() << " ";
        dQ.pop_back();
    }
    std::cout << std::endl;
}
void private_iterators_helping_fn::print_deque_iterator_front_while(std::deque<int> &dQ)
{
    /*
    -------------------------------------------------------------------------
    dQ.begin()
    ----------
    Returns a read/write iterator {***pointer***} that points to the first element in the %deque.
    Iteration is done in ordinary element order.
    -------------------------------------------------------------------------
    dQ.end()
    --------
    Returns a read/write iterator {***pointer***} that points one past the last element in the %deque.
    Iteration is done in ordinary element order.
    -------------------------------------------------------------------------
    */

    // Declare iterator to the DeQue, initialize it with 1st element
    std::deque<int>::iterator it = dQ.begin();

    // loop using the iterator pointer from begin() to end() of %deque.
    std::cout << "print_deque_iterator_front_while\n"
              << "DeQue Elements:\t";
    while (it != dQ.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}
void private_iterators_helping_fn::print_deque_iterator_front_for(std::deque<int> &dQ)
{
    /*
    -------------------------------------------------------------------------
    dQ.begin()
    ----------
    Returns a read/write iterator {***pointer***} that points to the first element in the %deque.
    Iteration is done in ordinary element order.
    -------------------------------------------------------------------------
    dQ.end()
    --------
    Returns a read/write iterator {***pointer***} that points one past the last element in the %deque.
    Iteration is done in ordinary element order.
    -------------------------------------------------------------------------
    */

    // loop using the iterator pointer from begin() to end() of %deque.
    std::cout << "print_deque_iterator_front_for\n"
              << "DeQue Elements:\t";

    // for (auto                   it = dQ.begin(); it <= dQ.end(); it++)
    for (std::deque<int>::iterator it = dQ.begin(); it <= dQ.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
void private_iterators_helping_fn::print_deque_iterator_back_while(std::deque<int> &dQ)
{
    /*
    -------------------------------------------------------------------------
    dQ.rbegin()
    ----------
    Returns a read/write "reverse" iterator {***pointer***} that points to the last element in the %deque.
    Iteration is done in "reverse" element order.
    -------------------------------------------------------------------------
    dQ.rend()
    --------
    Returns a read/write "reverse" iterator {***pointer***} that points to one before the first element in the %deque.
    Iteration is done in "reverse" element order.
    -------------------------------------------------------------------------
    */

    // Declare iterator to the DeQue, initialize it with 1st element
    std::deque<int>::reverse_iterator it = dQ.rbegin();

    // loop using the iterator pointer from begin() to end() of %deque.
    std::cout << "print_deque_iterator_back_while\n"
              << "DeQue Elements:\t";
    while (it != dQ.rend())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
}
void private_iterators_helping_fn::print_deque_iterator_back_for(std::deque<int> &dQ)
{
    /*
    -------------------------------------------------------------------------
    dQ.rbegin()
    ----------
    Returns a read/write "reverse" iterator {***pointer***} that points to the last element in the %deque.
    Iteration is done in "reverse" element order.
    -------------------------------------------------------------------------
    dQ.rend()
    --------
    Returns a read/write "reverse" iterator {***pointer***} that points to one before the first element in the %deque.
    Iteration is done in "reverse" element order.
    -------------------------------------------------------------------------
    */
    std::cout << "print_deque_iterator_back_for\n"
              << "DeQue Elements:\t";
    for (auto it = dQ.rbegin(); it <= dQ.rend(); it++)
        for (std::deque<int>::reverse_iterator it = dQ.rbegin(); it <= dQ.rend(); it++)
        {
            std::cout << *it << "\t";
        }
    std::cout << "\n";
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*TUPLE_H*/
