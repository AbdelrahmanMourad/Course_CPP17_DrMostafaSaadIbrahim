/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_QUEUE_H
#define MY_QUEUE_H
/*  
=================================================================================================
SUMMARY: queue
=================================================================================================
    Queue
        ● Recall the Queue Structure we built
            ○ First in first out strategy (FIFO)
            ○ How many projects might need it? A lot
            ○ So STL provides us for an implementation for it
        ● But we need queue for several data types: Integer, Double, Employees?
            ○ Use C++ templates
            ○ queue<int> q_int;
            ○ queue<employee> q_empl;
        ● What does it support?
            ○ Push (to add element) - by default at the end.
            ○ Front (to get top/front/first element)
            ○ Back (to get buttom/end/last element)
            ○ Empty (to know if empty() )
            ○ Size(): How many elements?

=================================================================================================
*/




/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <queue>
#include <deque>
#include <list>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
namespace namespace_queue
{
    void main1_Declaraions_Operations(void);
    void main2_Print_Queue(void);
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
void namespace_queue::main1_Declaraions_Operations(void)
{
    int x = 50;

    // Queue Declaration.
    std::queue<int> q1, q2;

    // Queue Operations.
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(x); // Add data to the end of the %queue.
    q1.pop();   // Removes 1st element.
    q1.back();  // Returns a read/write reference to the data at the {"last"} element of the %queue.
    q1.front(); // Returns a read/write reference to the data at the {"first"} element of the %queue.
    q1.size();  // Returns the number of elements in the %queue.
    q1.empty(); // Returns true if the %queue is empty.

    /*  specialized for int with a std::deque container.
            It constructs and inserts a new element at the end of the queue in place, avoiding unnecessary copies or moves. */
    q1.emplace();

    /*  swap function is an inline member function that:
            exchanges the contents of the current queue with those of the provided queue __q.
            This operation is performed in constant time and does not invalidate iterators or references. */
    q2.swap(q1);
}

void namespace_queue::main2_Print_Queue(void)
{
    // Deque for direct initialization.
    std::deque<int> dq1{1, 2, 3, 4, 5, 6, 7};

    // list for direct initialization.
    std::list<int> list1{1, 2, 3, 4, 5};

    // construct queue from deque and list as queues don't support direct initialization.
    std::queue<int> q1{dq1};                   // construct queue using deque.
    std::queue<int, std::list<int>> q2{list1}; // construct queue using list.

    // Print queue q1:
    while (!q1.empty())
    {
        std::cout << q1.front() << " "; // get front == 1st element of queue.
        q1.pop();                       // Remove front = 1st element of queue.
    }
    std::cout << std::endl;

    // Print queue q1:
    while (!q2.empty())
    {
        std::cout << q2.front() << " "; // get front == 1st element of queue... print it.
        q2.pop();                       // Remove front = 1st element of queue.
    }
    std::cout << std::endl;

    /*****************/
    std::queue<std::string> q_names;
    q_names.push("Abdelrahman");
    std::string Name = q_names.front();
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*QUEUE_H*/
