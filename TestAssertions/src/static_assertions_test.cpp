/*

Testing the C++ Static Assertions.

An static assertion is a check of a condition in COMPILE-TIME. 

static_assert( constant_expression , string_literal )

If constant_expression is 0 (false) at compile-time, the compilations fails, showing
in addition the message string_literal

*/

#include <iostream> // std::cout
// No headers necessary for static_assert()

// Aliases
using namespace std;

// Using template to specify a value when constructing the object
template<int Size>
class IntBuffer
{
    int values[Size];

    // Let's enforce this Size is small
    static_assert(Size < 100, "IntBuffer object must be smaller than 100" );
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Static Assertions:" << endl;
    cout << "------------------------------" << endl;

    // constant_expresion must be that, constant at compile time, so a "constexpr", like "const int"
    const int value = 5;
    static_assert(value > 4, "'value' variable must be bigger than 4");  // OK
    
    IntBuffer<10> small_buffer; // OK
    //IntBuffer<100> big_buffer;  // FAIL AT COMPILATION TIME

    cout << "THIS IS THE END LINE" << endl;
    
    return 0;
}