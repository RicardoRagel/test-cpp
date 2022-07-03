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

        A(int x)
        {
            cout << "(A) Non-default Constructor (x)" << endl;
        };

        A(int x, int y)
        {
            cout << "(A) Non-default Constructor (x, y)" << endl;

            x_ = x + 1;
            y_ = y + 1;
        };


        ~A()
        {
            cout << "(A) Default Destructor" << endl;
        };
    
    protected:
        int x_, y_;
};

// Derived class from A: B
class B : public A
{
    public: 
        B()
        {
            cout << "(B) Default Constructor" << endl;
        };

        B(int x)
        {
            cout << "(B) Non-default Constructor (x)" << endl;
        };
        
        B(int x, int y):A(x,y)
        {
            cout << "(B) Non-default Constructor (x, y)" << endl;
            cout << "(B) (x, y) = " << x_ << ", " << y_ << endl;
            x_ = x;
            y_ = y;
            cout << "(B) (x, y) = " << x_ << ", " << y_ << endl;
        };

        B(const B &b)
        {
            cout << "(B) Copy Constructor" << endl;
            x_ = b.x_;
            y_ = b.y_;
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

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Inheritance:" << endl;
    cout << "------------------------" << endl;

    // cout << endl << "* ABBA order of constructor and destructor in a derived class:" << endl;
    // B b;     // All default constructors

    // cout << endl << "* A derived class constructor calls to the default constructor of the base class if it doesn't define which one must be called:" << endl;
    // B b(1);  // Non-default constructor of B, but it calls to the default constructor of the base class because the B one doesn't call any other
    //B b(1,1);   // Non-default constructor of B, that calls to a non-default constructor of the base class because this B's constructor defines which constructor of the base class must be called

    // cout << endl << "* In case of create a new object assigning it to another one, the default constructor is not called. In this case, the constructor called is the 'Copy Constructor', that if it is not defined, it is the "Default Copy Constructor":" << endl;
    // A a1;
    // A a2 = a1;

    // cout << endl << "* The copy constructor can be defined as B(const B &b) and then we can define it as we prefer:" << endl;
    // B b1;
    // B b2 = b1;

    // cout << endl << "* ABBA order of constructor and destructors: The destructors are called from the last created to the first created:" << endl;
    // A a;
    // C c;

    // Other test to check the destructors order
    A a;
    B b;
    C c;

    return 0;
}