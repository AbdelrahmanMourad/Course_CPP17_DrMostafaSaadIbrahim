/*
=================================================================================================
SUMMARY: tuple
=================================================================================================
    Tuple
        ● It's a generalization of pair.
            ○ Need to include library: {"#include <tuple>"}
            ○ You declare it as this: {"""std::tuple<char, ,float, int, double> P1"""}
            ○ to fill it use this function {""P1=std::make_pair(first_val , second_val)""}
            ○ To access them in Tuple:
                - {"std::get <position> Tuple_Name"}
                -   std::get    <0>     (Tuple1)
                -   std::get    <1>     (Tuple1)
                -   std::get    <2>     (Tuple1)
                -   std::get    <3>     (Tuple1)
            ○ We can ""unpack"" the tuple values into separate variables using:
                - {""std::tie(var1,var2,var3)= Tuple1""}
                -   "std::tie(ch, val, name) = Tuple1;"
            ○ We can concatinate 2 tuples to return new (3rd) one:
                - "auto Tuple2 = std::tuple_cat(Tuple1, std::make_tuple(10.6, 'C'));"


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
#include <tuple>

/*  =================================================================================================
                                    Declarations/ Prototypes
    =================================================================================================  */
namespace namespace_tuple
{
    void main1_Declaraions_Operations(void);
};

/*  =================================================================================================
                                    Implementations
    =================================================================================================  */
/*_________________Public_Functions_________________*/
void namespace_tuple::main1_Declaraions_Operations(void)
{
    std::tuple<char, int, std::string> Tuple1;
    Tuple1 = std::make_tuple('C', 10, "Mostafa");

    // To access element in Tuple:  {"std::get <position> Tuple_Name"}
    std::cout << "std::get<0>(Tuple1)" << std::get<0>(Tuple1) << "\n"
              << "std::get<1>(Tuple1)" << std::get<1>(Tuple1) << "\n"
              << "std::get<2>(Tuple1)" << std::get<2>(Tuple1) << "\n";

    // We can Compare Tuples by 1st element.
    std::cout << "(Tuple1 <= Tuple1) = " << (Tuple1 <= Tuple1) << "\n";

    // Declare container variables to use in next step.
    char ch;
    int val;
    std::string name;

    // We can ""unpack"" the tuple values into separate variables using {""std::tie(var1,var2,var3)= Tuple1""}
    std::tie(ch, val, name) = Tuple1;

    // We can concatinate 2 tuples to return new (3rd) one.
    auto Tuple2 = std::tuple_cat(Tuple1, std::make_tuple(10.6, 'C'));

    // C++17 some nucer syntax. Don't try unless C++17 Comilation.
    int c, d;
    // auto [c, d] = std::make_tuple(4, 5);
}

/*  =================================================================================================
                                    End of Guard File
    =================================================================================================  */
#endif /*TUPLE_H*/
