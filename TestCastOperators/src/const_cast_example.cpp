/*

Testing C++ Const Casting

It is simply used to set or remove the "const" modifier of a type

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// Functions to be used by the last examples
void printIt(char *str)
{
    cout << str << endl;
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Static Casting Test:" << endl;
    cout << "---------------------------" << endl;

    cout << "" << endl;

    const char c_const = 'a';
    cout << "A const char: " << c_const << endl;

    // c_const = 'b';                       // Compile-time error: non-modifiable

    char c = c_const;                       // OK

    char * c_ptr = &c;                      // OK
    //char * c_ptr = &c_const;              // Compile-time error: it must be a "const char *"
    const char * c_const_ptr = &c_const;    // OK

    // How can we get that?
    //char * c_const_ptr = static_cast<char *>(&c_const); // Static cast cannot be used with const nor other modifiers
    char * c_ptr_non_const = const_cast<char *>(&c_const); 
    cout << "A pointer to that char: " << *c_ptr_non_const << endl;
    *c_ptr_non_const = 'b';
    cout << "A pointer to that char: " << *c_ptr_non_const << endl;
    cout << "But the const char has not been modified!!! : " << c_const << endl;

    // What is then the utility??? When we need to call a function which argument for example 
    // is non-const and aur variable (to be passed) is const.
    const char * str_const = "This is a constant string";
    //printIt( str ); // Not valid, the argument must me non-const
    printIt( const_cast<char *> (str_const)  );

    cout << "" << endl;

    return 0;
}