/*

Testing GDB
-----------

Just a example source file with some bugs to test GDB.

Check the README.md file for more information.
*/

#include <iostream> // std::cout
#include <unistd.h> // sleep(), usleep()

// Aliases
using namespace std;

int getDouble(const int &arg)
{
    return arg*2;
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test GDB Basics:" << endl;
    cout << "----------------------" << endl;

    int a = 10;
    int b = 0;

    int *v = new int[3];
    *(v)    = 2;
    *(v+1)  = 4;
    *(v+2)  = 6;

    while (a > b) 
    {
        int c = getDouble(a);
        if(b>=0)
            b -= c;
        else
            b += c;
    }

    cout << "" << endl;

    return 0;
}