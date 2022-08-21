/*

Testing GDB
-----------

Just a example source file with a bug that produces a segmentation fault

Check the README.md file for more information.
*/

#include <iostream> // std::cout
#include <cstdlib>  // atoi

// Aliases
using namespace std;

int getDouble(const int &arg)
{
    return arg*2;
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test GDB SegFault:" << endl;
    cout << "-------------------------" << endl;

    int second_argv = 0;

    if(argc == 2)
    {
        second_argv = atoi(argv[2]); // NOTICE THE ERROR: IT IS GETTING THE THIRD ARG
    }

    cout << "The second argv = " << second_argv << endl;

    cout << "" << endl;

    return 0;
}