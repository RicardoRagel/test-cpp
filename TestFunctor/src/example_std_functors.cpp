/*

Testing the C++ functors of the standard library

*/

#include <iostream>     // std::cout
#include <functional>   // std predefined functors

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test STD Functors:" << endl;
    cout << "-------------------------" << endl;
    cout << "" << endl;

    // To call them directly, first it is necessary to construct their objects
    // and later call them, so we have to add {} or () to initialize them
    int result1 = plus<int>{}(3,2);
    int result2 = plus<int>()(3,2);  // both are the same

    cout << "Using std::plus "       << plus<int>()(3,2) << endl;
    cout << "Using std::multiplies " << multiplies<int>{}(3,2) << endl;
    cout << "Using std::modulus "    << modulus<int>()(3,2) << endl;
    cout << "Using std::equal_to "   << equal_to<int>{}(3,2) << endl;

    return 0;
}