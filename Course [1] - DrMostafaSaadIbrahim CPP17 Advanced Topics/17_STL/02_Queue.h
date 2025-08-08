/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef QUEUE_H
#define QUEUE_H

/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <queue>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
namespace queue
{
    void main1_Declaraions_Operations();
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
void main1_Declaraions_Operations()
{

    int x = 50;

    // Queue Declaration.
    std::queue<int> q1,q2; 

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

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*QUEUE_H*/
