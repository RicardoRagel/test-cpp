/*

A real example: Let's create a Templated function setting
that this function returns different types depending of a condition

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// The following function return the maximum number between 2, but always
// returning the result with the type of the first argument.
template<typename T, typename U>
auto findMax1(T a, U b) -> decltype( a )
{
    return (a > b) ? a : b;
}

// Let's do the same but returning the type of the lower one
template<typename T, typename U>
auto findMax2(T a, U b) -> decltype( (a < b) ? a : b )
{
    return (a > b) ? a : b;
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Real Inference:" << endl;
    cout << "--------------------------" << endl;
    cout << "" << endl;

    int a = 20;
    double b = 30.53;

    cout << findMax1( a, b ) << " --> The second (" << b << ") is bigger, but the first one was an integer" << endl;

    double aa = 20.2;

    cout << findMax1( aa, b ) << " --> In this case, both were double" << endl;

    cout << findMax2( a, b ) << " --> Should it be an integer??? No, in this case, decltype is receiving "
    << "and expresion, so it doesn't return an int, but an int&. Why? This is how it works in case of expresions " << endl;

    cout << typeid(findMax2( a, b )).name() << endl;

    return 0;
}