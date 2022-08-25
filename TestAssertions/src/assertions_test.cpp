/*

Testing the C++ Assertions.

An assertion is a check of a condition in RUN-TIME. 

assert(int expression)

If it is 0 (false), this information is sent to the standard output error and the
abort() function is called (=> Aborted (core dumped)). Otherwise, the program
continues as usual.

*/

#include <iostream> // std::cout
#include <assert.h> // assert()


// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Clean Test:" << endl;
    cout << "------------------" << endl;

    string str = "String 1";

    assert(str == "String 1");  // OK
    
    assert(str == "String 2");  // Run-time fail

    cout << "THIS IS THE END LINE" << endl;
    
    return 0;
}