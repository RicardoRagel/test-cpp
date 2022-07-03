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
};

// Derived class from A: B
class B : public A
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
};

// Another independent class
class C
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


template<class T, class C>
bool isDerivedFrom()
{
    return std::is_base_of<T,C>();
}


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Inheritance Checker:" << endl;
    cout << "--------------------------------" << endl;

    cout << "B is derived from A: " << isDerivedFrom<A,B>() << endl;
    cout << "C is derived from A: " << isDerivedFrom<A,C>() << endl;

    return 0;
}