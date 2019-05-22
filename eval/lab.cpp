
#include <eval/is.hpp>
#include <eval/tests.hpp>

#include <iostream>
#include <vector>
#include <set>
#include <string>

int main()
{
    std::cout << std::boolalpha;

    using namespace eval;
    std::cout <<  is(std::string{"MUNI"}     , in    , {"MUNI", "SUPR", "PFD", "CORP"}                        ) << std::endl;
    std::cout <<  is("CORP"                  , not_in, {"MUNI", "SUPR", "PFD", "CORP"}                        ) << std::endl;
    std::cout <<  is("CORP"                  , not_in, {"MUNI", "SUPR", "PFD", std::string{"CORP"} }          ) << std::endl;
//    std::cout <<  is("CORP"                  , in    , std::vector<std::string>{"MUNI", "SUPR", "PFD", "CORP"}) << std::endl;
    std::cout <<  is(10                      , not_in, std::vector<int>{1, 2, 3, 4, 10}                       ) << std::endl;
    std::cout <<  is(1                       , in    , {1, 2, 3, 4, 10}                                       ) << std::endl;
    std::cout <<  is(1.2                     , in    , std::set<double>{1.3, 2.0, 3.4, 4.3, 10.0}             ) << std::endl;

    // Note - both the ranges passed to `are` function need to be sorted
//    std::cout << are(std::vector<int>{1, 10} , not_in, std::vector<int>{1, 2, 3, 4, 10}                       ) << std::endl;
//    std::cout << are({1, 10}                 , in    , {1, 2, 3, 4, 10}                                       ) << std::endl;
//    std::cout << are({"CORP", "MUNI"}        , in    , {"CORP", "MUNI", "PFD", "SUPR"}                        ) << std::endl;
    // char arr[] = "CORP";
    // std::cout << are(arr                  , in    , "CORP"                        ) << std::endl;
    // std::cout << are({"CORP", "MUNI"}        , in    , {"CORP", "MUNI", "PFD", std::string{"SUPR"}}           ) << std::endl;
}
