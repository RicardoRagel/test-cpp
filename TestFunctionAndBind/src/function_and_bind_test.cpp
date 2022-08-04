/*

Testing the C++ std::function<> type and std::bind() function 

*/

#include <iostream> // std::cout
#include <functional> // std::function

// Aliases
using namespace std;

using namespace std::placeholders;

// A simple function to be pointed from the main()
string get_string(string str, int16_t num)
{
    return str + " " + to_string(num);
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test function and bind:" << endl;
    cout << "------------------------------" << endl;

    cout << "" << endl;

    // Calling directly to the function    
    // cout << get_string("The number is:", 1) << endl;

    /*
        std::function:  encapsulates a function pointer (similar to the ones used before C++11) 
                        and can be used as they are.
                        
                        It is templataized by the return value of the function and the arguments that it receives.
    */

    std::function < string (string, int16_t) > functionPtr = get_string;

    cout << "Using std::function pointer: " << functionPtr("The number is:", 2) << endl;

    /*
        std::bind:  it allows to create a function pointer but setting a default values to the arguments of the function.
                    It returns a new function pointer (std::funciton) but just templatized with the non-default arguments

                    Note: it is necessary adding the namespace std::placeholders to be able to use "_1", "_2".

                    What does "_1" mean? It means that the first argument of the new function pointer will be in the position
                    where we write "_1" in the std::bind function arguments. 
    */
    
    // Example: let's say we want to use the previous function but setting always the same string message str
    // We can use both, directly the original function or the previous function pointer.
    //std::function < string (int16_t) > functionPtrSimple = std::bind(functionPtr, "The number is:", _1);
    std::function < string (int16_t) > functionPtrSimple = std::bind(get_string, "The number is:", _1);

    // In the previous bind, "_1" indicates that the function pointer argument, the int16_t will be the second argument of the function get_string

    cout << "Using std::bind function pointer: " << functionPtrSimple(3) << endl;


    return 0;
}