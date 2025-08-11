/*  
=================================================================================================
SUMMARY: STL
=================================================================================================
    ● The 4 core fundamental topics in CS
        ○ Programming
        ○ Algorithms
        ○ Data Structures
        ○ OOP
    ● Side note: Other fundamental topics
        ○ Software Engineering, Design Patterns, Databases, Operating Systems, Networking

-------------------------------------------------------------------------------------------------
Recall Queue Data Structure
-------------------------------------------------------------------------------------------------
    ● It has internally an {"""array"""} and support following operations:
        ○ "void add_end(int value)": add to the end of current array
        ○ "void add_front(int value)": add to the front of this array
        ○ "int remove_front()": remove the front value and remove it. 
            ■ Return the value
        ○ "void print()": print the array

-------------------------------------------------------------------------------------------------
Data Structure
-------------------------------------------------------------------------------------------------
    ●   In many cases, you will need to organize, process and retrieve data in some 
        specific way, similar to our queue
    ●   You typically define a class, inside it data (e.g. array) and operations on data
    ●   We call this class a ""{data structure}"".
    ●   In practice, same data structure needs repeat.
        ○   This is what a data structure course teaches
            ■   Basic structures: 
                - queue, 
                - priotity_queue,
                - dequeue,
                - stack, 
                - pair,
                - tuple, 
                - iterator,
                - vector, 
                - STL_string,
                - STL_algorithm
                - linked list, 
                - binary search tree,
                - set,
                - unordered_set,
                - Map
            ■   Advanced: 
                - Hash table, 
                - balanced binary search tree, 
                - trie, 
                - segment tree
-------------------------------------------------------------------------------------------------
STL
-------------------------------------------------------------------------------------------------
    ●   STL: Implemented very efficient data structures to directly use
        ○   They are called containers
        ○   Learning them = makes studying data structures course easier
        ○   Using templates: Generic containers
    ●   STL also provides set of algorithms to act on these containers
    
    1.  {"Templates"}: make {"algorithms"} independent of the {"data types"}.
    2.  {"Iterators"}: make {"algorithms"} independent of the {"containers"}.



=================================================================================================   
*/