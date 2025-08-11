/*
=================================================================================================
SUMMARY: priority_queue
=================================================================================================
    priority_queue
        ● Located in the <queue> library.
        ● Container adapter that provides constant time access to the largest (by default) element.
        ● Internally uses a heap structure (usually std::vector).
        ● Elements are {"""always sorted by priority"""} (largest or smallest, depending on comparator).

        ○ push(value)      = Add element
        ○ top()            = Get top element --> Get highest-priority element
        ○ pop()            = Remove top --> removve highest-priority element
        ○ size()           = Number of elements
        ○ empty()          = Is the queue empty?

        ● Custom comparators allow min-heap or user-defined ordering.
        ● Useful for scheduling, greedy algorithms, and anytime you need quick access to the highest/lowest priority item.


=================================================================================================
SUMMARY: STL Queue, Deque, and Priority Queue Demonstration
=================================================================================================
This application demonstrates the usage and operations of three STL container adapters:

1. Queue (`namespace_queue`)
   - FIFO structure: elements are added at the back and removed from the front.
   - Shows declaration, basic operations (push, pop, front, back, size, empty), and printing.

2. Deque (`namespace_deque`)
   - Double-ended queue: allows insertion and removal from both ends.
   - Demonstrates declaration, operations (push_front, push_back, pop_front, pop_back), and printing.

3. Priority Queue (`namespace_priority_queue`)
   - Heap-based structure: always provides access to the highest-priority element.
   - Demonstrates:
     - Max-heap (default)
     - Min-heap (using `std::greater`)
     - Custom comparator
     - Usage with user-defined types
     - Printing and basic operations

Each namespace contains example functions to illustrate the main features and usage patterns of these containers.
=================================================================================================
*/

/*  =================================================================================================
                                    Header Guard File
    =================================================================================================  */
#ifndef MY_PRIORITY_DEQUE_H
#define MY_PRIORITY_DEQUE_H

/*  =================================================================================================
                                    Included Libraries
    =================================================================================================  */
#include <iostream>
#include <queue>

/*  =================================================================================================
                                    Declarations
    =================================================================================================  */
struct Task /*Using with user-defined types*/
{
    int priority;
    std::string name;
    bool operator<(const Task &other) const
    {
        return priority < other.priority; // max-heap by priority
    }
};

struct CompareAbs /*Custom comparator (struct)*/
{
    bool operator()(int a, int b)
    {
        return std::abs(a) > std::abs(b);
    }
};
/*  =================================================================================================
                                    Prototypes
    =================================================================================================  */
namespace namespace_priority_queue
{
    void main1_Declaraions_Operations(void);
    void main2_max_heap();
    void main3_min_heap();
    void main4_custom_comparator();
    void main5_user_type();
};

namespace private_priority_queue_helping_fn
{
    void print(std::priority_queue<int> &pq);
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
/*_________________Private_Functions_________________*/
void private_priority_queue_helping_fn::print(std::priority_queue<int> &pq)
{
    std::cout << "Priority Queue elements: ";
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
}

/*_________________Public_Functions_________________*/
void namespace_priority_queue::main1_Declaraions_Operations(void)
{
    // order from big to small.
    std::priority_queue<int> pq; // Same as std::priority_queue<int, std::vector<int>, std::less<int>>
    pq.push(3);                  // 3
    pq.push(5);                  // 5 3
    pq.push(1);                  // 5 3 1
    pq.push(7);                  // 7 5 3 1
    pq.push(0);                  // 7 5 3 1 0

    private_priority_queue_helping_fn::print(pq);
    // use (-ve) number to sort small to large.
}

void namespace_priority_queue::main2_max_heap()
{
    std::priority_queue<int> pq; // Largest element is always at the top.
    pq.push(5);                  // 5
    pq.push(1);                  // 5 1
    pq.push(10);                 // 10 5 1

    std::cout << "Max element: " << pq.top() << "\n"; // 10
    pq.pop();
    std::cout << "Next max: " << pq.top() << "\n"; // 5
}

void namespace_priority_queue::main3_min_heap()
{
    /*
    ------------------------------------------------------
    What does this mean?
        ●   ""std::priority_queue"" is a container adapter that provides constant time access to the "top" element, which is the highest priority.
        ●   By default, it is a max-heap (largest element on top).
        ●   The template parameters let you customize its behavior.

    Template Parameters:
        1.  ""int""
            The type of elements stored (int in this case).
        2.  ""std::vector<int>""
            The underlying container used to store the elements.
            By default, {""std::vector""} is used, but you could use {""std::deque""} as well.
        3.  ""std::greater<int>""
            The comparator that determines the priority.
            ○   By default, ""std::less<int>"" is used (max-heap).
            ○   Using ""std::greater<int>"" makes it a min-heap (smallest element on top).
    ------------------------------------------------------
    */

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // Smallest element is always at the top.
    pq.push(5);
    pq.push(1);
    pq.push(10);

    std::cout << "Min element: " << pq.top() << "\n"; // 1
    pq.pop();
    std::cout << "Next min: " << pq.top() << "\n"; // 5

    std::priority_queue<int, std::deque<int>, std::greater<int>> pq2; // Smallest element is always at the top.
    pq2.push(-10);
    pq2.push(2);
    pq2.push(-3);
    std::cout << "Smallest abs: " << pq2.top() << "\n"; // 2
}

void namespace_priority_queue::main4_custom_comparator()
{
    std::priority_queue<int, std::vector<int>, CompareAbs> pq1; // Smallest element is always at the top.
    pq1.push(-10);
    pq1.push(2);
    pq1.push(-3);
    std::cout << "Smallest abs: " << pq1.top() << "\n"; // 2
}

void namespace_priority_queue::main5_user_type()
{
    std::priority_queue<Task> pq;
    pq.push({2, "Low"});
    pq.push({10, "High"});
    pq.push({5, "Medium"});

    std::cout << "Top task: " << pq.top().name << "\n"; // High
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*PRIORTITY_DEQUE_H*/
