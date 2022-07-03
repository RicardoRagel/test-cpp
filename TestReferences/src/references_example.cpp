/*

Testing the C++ pointers and references

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// A class
class A
{
    public: 
        A()
        {
            cout << "(A) Constructor" << endl;
        };

        A(const A &a)
        {
            cout << "(A) Copy Constructor" << endl;
        };

        ~A()
        {
            cout << "(A) Destructor" << endl;
        };

        int value = 33;
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test References:" << endl;
    cout << "-----------------------" << endl;

    cout << endl << "* Using a pointer:" << endl;

    int x = 4;
    int* ptr_x = &x;
    cout << "Pointer to x dir: " << ptr_x << endl;
    cout << "Pointer to x value: " << *ptr_x << endl;

    cout << endl << "* Using a reference (~ a new name for this same variable = memory entry):" << endl;

    int y = 4;
    int& ref_x = x;
    cout << "Reference to x dir: " << &ref_x << endl;
    cout << "Reference to x value: " << ref_x << endl;

    cout << endl << "* Using a pointer to a Class:" << endl;
    //A a;
    //A* ptr_a = &a;
    A* ptr_a = new A();
    cout << "Pointer to A dir: " << ptr_a << endl;
    cout << "Pointer to A value: " << ptr_a->value << endl;

    cout << endl << "* Using a reference to a Class:" << endl;
    //A a;
    //A& ref_a = a;
    A& ref_a = * new A();
    cout << "Reference to A dir: " << &ref_a << endl;
    cout << "Reference to A value: " << ref_a.value << endl;
    
}