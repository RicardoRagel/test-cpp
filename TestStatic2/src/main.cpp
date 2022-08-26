/*

Testing the C++ Keyword: static

*/

#include <iostream> // std::cout

#include "Class.hpp"  // Notice it is declaring "extern int extern_global_var;"

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Static 2:" << endl;
    cout << "--------------------" << endl;

    std::cout << "Static variables class members can be accessed with no objects (if public): " << Class::variable << endl;
    std::cout << "Static functions class members can be accessed with no objects (if public): " << Class::getStaticVariable() << endl;

    // WE CANNOT CALL TO A STATIC FUNCTION DEFINED IN ANOTHER FILE, ALTHOUGH IT IS IN THE HEADER
    non_static_print();
    // static_print(); 
    
    // A STATIC FUNCTION OR VARIABLE (NON-MEMBER OF A CLASS) CAN ONLY BE CALLED FROM HIS OWN LOCAL FILE
    Class obj;
    obj.callStaticPrint();

    // Using the extern variable
    cout << "Global var: " << extern_global_var << endl;

    // Accessing to the Class.cpp named variable
    extern int named_global_var;
    cout << "Named namespace Global var: " << named_global_var << endl;

    // Trying to access to the unnamed namespace variable -> LINKING FAIL
    // extern int unnamed_global_var;
    // cout << "Unnamed namespace Global var: " << unnamed_global_var << endl;

    return 0;
}