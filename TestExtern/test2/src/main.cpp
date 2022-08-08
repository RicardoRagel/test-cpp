/*

Testing the C++ extern keyword.

*/

#include <iostream> // std::cout
#include "header.hpp"

// Aliases
using namespace std;

// main.cpp or module.cpp must initialize the extern variable. Otherwise a linking error will appear
int global_int; // in other words, initialization to 0

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test extern:" << endl;
    cout << "-------------------" << endl;

    cout << "" << endl;
    
    cout << "Using variable global_int, that is defined in a header: " << global_int << endl;
    cout << "Using variable global_int through a function in the module, that is also including in a header: " << get_global_var() << endl;

    return 0;
}