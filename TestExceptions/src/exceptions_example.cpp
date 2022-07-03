/*

Testing the C++ Operands

*/

#include <iostream> // std::cout

// Aliases
using namespace std;


class A
{
    public:
        A() 
        {
            // throw 42;
        }

        ~A()
        {
            throw 42;
        }
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Exceptions:" << endl;
    cout << "-----------------------" << endl;

    // Test 1
    // try
    // {
    //     throw 33;
    // }
    // catch(int a)
    // {
    //     cout << a << endl;
    // }

    // Test 2: In this case, the throw doesn't appear due to ~A() is called once try has finished due to ir is a local var
    try
    {
        A a;
        cout << "Ending try..." << endl;
    }
    catch(int a)
    {
        cout << a << endl;
    }

    cout << "Ending program..." << endl;
    return 0;
}