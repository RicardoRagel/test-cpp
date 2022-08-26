/*

Testing the C++ Inheritance. Notice that if we declare the call to the Base constructor within
the Derived constructor (line 32), the order is the same (ABBA), but perhaps it is more clear
for the maintainers.

Obviously, avoid thinking of a possible AABBA :)
*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// Base class: A
class A
{
    public: 
        A()
        {
            cout << "(A) Default Constructor" << endl;
        };

        ~A()
        {
            cout << "(A) Default Destructor" << endl;
        };    
};

// Derived class from A: B
class B : public A
{
    public: 
        B() : A()
        {
            cout << "(B) Default Constructor" << endl;
        };

        ~B()
        {
            cout << "(B) Default Destructor" << endl;
        };
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Inheritance:" << endl;
    cout << "------------------------" << endl;

    B b;

    return 0;
}