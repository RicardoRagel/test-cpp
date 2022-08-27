/*

Testing C++ Static Casting

static_cast can be used to perform any other non-pointer conversion that could also be 
performed implicitly, like for example standard conversion between fundamental types, but
it will check any incongruence in compile-time.

Notice that static cast can be used to cast pointers from B to D and D to B, but,
unlike dynamic cast, it will not perform any checking about it is valid (it is a full
object), so it should not be used at least the developer knows exactly what is doing.

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Static Casting Test:" << endl;
    cout << "---------------------------" << endl;

    cout << "" << endl;

    // No difference for casting values. Although it is better to make some checks
    char ch = 69;
    cout << "Char: " << ch << endl; 
    int ch_int = (int)ch;
    cout << "Explicit: " << ch_int << endl; 
    ch_int = static_cast<int>(ch);
    cout << "Static cast: " << ch_int << endl; 

    // Explicit C Casting
    char c = 69;            // 1 byte
    // int *ptr = &c;       // No compiling, it is necessary a casting
    int *ptr = (int*)&c;    // A pointer to 4 bytes, but it is actually 1
    cout << "Explicit: " << *ptr << endl;   // Reading 4 bytes of 1 byte !!!
    // *ptr = 1000;         // it may generate runtime error or will overwrite some adjacent memory.

    // Using C++ Casting
    char *ptr_safe = static_cast<char*>(&c);
    cout << "Static cast: " << *ptr_safe << endl;
    // int *ptr_safe_int = static_cast<int*>(&c); // compile-time error. It advertises that it is an invalid conversion :)

    cout << "" << endl;

    float fl = 10;
    int32_t i32 = static_cast<int32_t>(fl);
    cout << "Float: " << fl << " to Int32t: " << i32 << endl;
    int8_t i8 = static_cast<int8_t>(fl);
    cout << "Float: " << fl << " to Int8t: " << (int)i8 << endl; // cast here only for cout
    fl = 1000;
    i32 = static_cast<int32_t>(fl);
    cout << "Float: " << fl << " to Int32t: " << i32 << endl;
    i8 = static_cast<int8_t>(fl);
    cout << "Float: " << fl << " to Int8t: " << (int)i8 << endl; // cast here only for cout

    

    return 0;
}