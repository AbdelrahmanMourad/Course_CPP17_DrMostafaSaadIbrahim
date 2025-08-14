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
    ● We can deal with it with ++ and --
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

-------------------------------------------------------------------------------------------------
Using iterators: Iterate backward
-------------------------------------------------------------------------------------------------
    ● To iterate backward we use rbegin (r for reverse)
    ● Think of it as if the content is reversed
        ○ So u again u move with ++
                |---------------------------------------------------------------|
                |   void print_back1 (std::deque<int> &dq)                      |
                |   {                                                           |
                |       std::cout<<"Queue elements (back): ";                   |
                |                                                               |
                |       // reverse iterator.                                    |
                |       std::deque<int::reverse_iterator it = q.rbegin();       |
                |                                                               |
                |       while(it != q.rend() )                                  |
                |       {                                                       |
                |           std::cout<< *it <<" ";                              |
                |       }                                                       |
                |       std::cout<<"\n";                                        |
                |---------------------------------------------------------------|
                |   void print_back2 (std::deque<int> &dq)                      |
                |   {                                                           |
                |       std::cout<<"Queue elements (back): ";                   |
                |                                                               |
                |       for(auto it = q.rbegin(); it != q.rend(); ++i)          |
                |       {                                                       |
                |           std::cout<< *it <<" ";                              |
                |       }                                                       |
                |       std::cout<<"\n";                                        |
                |   {                                                           |
                |---------------------------------------------------------------|

-------------------------------------------------------------------------------------------------
Const iterator
-------------------------------------------------------------------------------------------------
    ● cbegin/cend instead of begin/end
    ● The same as we did, just iterator is const, 
    ● But you can’t change value while iterating
        ○ Good for communicating intentions
    ● Similarly: crbegin, crend

                |-------------------------------------------------------------------|
                |   void print_front_const( std::deque<int> &dQ )                   |
                |   {                                                               |
                |       std::cout<< "Queue elements (front): ";                     |
                |                                                                   |
                |       std::deque<int>::const_iterator it = dQ.cbegin();           |
                |                                                                   |
                |       while( it != dQ.cend() )                                    |
                |       {                                                           |
                |           std::cout<<*it<<" ";                                    |
                |           // *it = 10;            // Can't - read only - CONST.   |
                |           ++it;                                                   |
                |       }                                                           |
                |       std::cout<<"\n";                                            |
                |   }                                                               |
                |                                                                   |
                |-------------------------------------------------------------------|

-------------------------------------------------------------------------------------------------
Many iterators
-------------------------------------------------------------------------------------------------
    ● You can actually iterate on most data structures 
        ○ can’t on stack, queue, priority_queue
    ● So let’s iterate on string
        ○ E.g. string::iterator it;
                |-------------------------------------------------------------------|
                |   int count_lowers ( const std::string & str )                    |
                |   {                                                               |
                |       int cnt = 0;                                                |
                |                                                                   |
                |       for( auto it = str.begin(); it != str.end(); ++it )         |
                |       {                                                           |
                |           char ch = *it;                                          |
                |           cnt += ( islower(ch) > 0 );                             |
                |       }                                                           |
                |       return cnt;                                                 |
                |   }                                                               |
                |-------------------------------------------------------------------|

-------------------------------------------------------------------------------------------------
Next
-------------------------------------------------------------------------------------------------
    ● In next videos, we will learn other data structures
        ○ They also support iterators!
    ● You will see operations by these containers
        ○ E.g. erase element using iterator or insert element/group of elements
        ○ Algorithms that takes iterator begin/end to e.g. search
                |-------------------------------------------------------------------|
                |   void more ( )                                                   |
                |   {                                                               |
                |       vector <int> :: iterator it1;                               |
                |                                                                   |
                |       set <string> :: iterator it2;                               |
                |                                                                   |
                |       // Each iterm is: pair <int , string>                       |
                |                                                                   |
                |                                                                   |
                |       for( auto it = str.begin(); it != str.end(); ++it )         |
                |       {                                                           |
                |           char ch = *it;                                          |
                |           cnt += ( islower(ch) > 0 );                             |
                |       }                                                           |
                |       return cnt;                                                 |
                |   }                                                               |
                |-------------------------------------------------------------------|



=================================================================================================
*/

/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_ITERATORS_H
#define MY_ITERATORS_H

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
    void main2_lets_play(void);
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
void namespace_STL_Iterators::main2_lets_play(void)
{
    std::deque<int> dQ{1, 2, 3, 4, 5};

    std::deque<int>::iterator it = dQ.begin() + 3; // FORTH element position.
    // auto                   it = dQ.begin() + 3; // FORTH element position.
    std::cout << *it << "\n"; // 4

    std::cout << *(it--) << "\n"; // 4 then move to 3rd position.
    std::cout << *it << "\n";     // 3

    std::cout << *(--it) << "\n"; // 2 moved to 2nd position first then printed.
    std::cout << *it << "\n";     // 2 Now on 2nd

    std::cout << *(it + 3) << "\n"; // 5th position.
    it += 3;
    std::cout << *it << "\n"; // 2 Now on 5th position.

    // reset all to 10.
    // for (auto                   it = dQ.begin();it != dQ.end();++it)
    for (std::deque<int>::iterator it = dQ.begin(); it != dQ.end(); ++it)
    {
        *it = 10;
    }
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
    std::cout << "print_deque_normal_back_while (back):\n"
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
    for (std::deque<int>::iterator it = dQ.begin(); it < dQ.end(); it++)
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
    std::cout << "print_deque_iterator_back_while (back):\n"
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
    std::cout << "print_deque_iterator_back_for (back):\n"
              << "DeQue Elements:\t";
    for (auto it = dQ.rbegin(); it < dQ.rend(); it++)
        for (std::deque<int>::reverse_iterator it = dQ.rbegin(); it <= dQ.rend(); it++)
        {
            std::cout << *it << " ";
        }
    std::cout << "\n";
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*TUPLE_H*/
