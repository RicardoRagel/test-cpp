/*

Testing the C++ extern keyword.

Using a global variable and a global function defined in other program (that will be obviously linked to this one).

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

extern int global_int;
extern int get_global_int_2();

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test extern:" << endl;
    cout << "-------------------" << endl;

    cout << "" << endl;
    
    cout << "File 1 is using the variable global_int, that is defined in File 2 as: " << global_int << endl;
    cout << "File 1 is using the function get_global_int_2, that is defined in File 2 and returns: " << get_global_int_2() << endl;


    return 0;
}