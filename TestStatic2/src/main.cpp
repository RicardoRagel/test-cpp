/*

Testing the C++ Keyword: static

*/

#include <iostream> // std::cout

#include "Class.hpp"

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

    return 0;
}