/*

Testing the C++ Inheritance

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
    
        void foo()
        {
            cout << "(A) foo()" << endl;        
        }
};

// Derived class from A: B
class B
{
    public: 
        B()
        {
            cout << "(B) Default Constructor" << endl;
        };

        ~B()
        {
            cout << "(B) Default Destructor" << endl;
        };

        void foo()
        {
            cout << "(B) foo()" << endl;        
        } 
};

// Another independent class
class C : public A, public B
{
    public: 
        C()
        {
            cout << "(C) Default Constructor" << endl;
        };
        ~C()
        {
            cout << "(C) Default Destructor" << endl;
        };
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Multi Inheritance:" << endl;
    cout << "------------------------------" << endl;

    C c;
    // c.foo();     // AMBIGUOUS
    
    A* a = &c;
    a->foo();       // For sure, this is the A's one.

    return 0;
}