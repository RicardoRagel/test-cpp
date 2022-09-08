/*

Testing C++ Constructors

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

int val = -1;

class A
{
public:
    A()
    {
        cout << "Constructor" << endl; 
        val = 1; 
    }
    ~A() 
    { 
        cout << "Destructor" << endl; 
        val = 0;
    }
    A(const A &a)
    {
        cout << "Copy Constructor" << endl;
    };
};

A make_a()
{
    A a {};
    
    return a;

    // or return A {};
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Constructors:" << endl;
    cout << "-------------------------" << endl;

    // Test 1: The object created in make_a() is created and destroyed within the function 
    // cout << "Previous: " << val << endl;
    // make_a();
    // cout << "After: " << val << endl;

    // Test 2: In case of assign it, it is not destroyed. Why?
    // This is due to actually, the object is not created twice, it is only created one, so it will 
    // be destroyed when the one in the large scope ends. This is due to the compiler.
    // Avoid thinking in that the copy constructor is called. It would happen in case of create one and
    // later create another one = to the previous one
    cout << "Previous: " << val << endl;
    A a = make_a();
    cout << "After: " << val << endl;

    cout << "-- THE END -- " << endl;

    return 0;
}