/*

Testing the C++ Keyword: const

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// Function to tests
int fun1(int* x)
{
    return *x;
}
int fun2(const int* x)
{
    return *x;
}

// A class with a const member (= it doesn't modify anything)
class A
{
    public:
        A(int v = 0)
        {
            value = v;
        }

        int getValue() const
        {
            // value = 33;      MAKE ERROR: In a const function we cannot modified anything
            // setValue(33);    MAKE ERROR: In a const function we cannot call to non-const functions
            return value;
        }

        void setValue(int v)
        {
            value = v;
        }

    private:
        int value;
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Const:" << endl;
    cout << "--------------------" << endl;

    cout << endl << "- A const variable must be initialized, because we cannot modified it later." << endl;
    //const int a;      MAKE ERROR
    const int a = 1;
    // a = 2;           MAKE ERROR

    /*
    Note about how to read complex variables in C++: https://www.codeproject.com/Articles/7042/How-to-interpret-complex-C-C-declarations

    They must be read from right to left.

    const int * p;  => p is a pointer to a integer constant value
    int * const p;  => p is a constant pointer to an integer value

    They are different, due to the const is applied to different things.
    */

    cout << endl << "- A pointer to a const int ( = cont int*) can not modified the value of the int, although the integer itself could be modified because it is not const. " << endl;
    int b = 1;
    const int* ptr_b = &b;
    b = 2;
    //*ptr_b = 3;           MAKE ERROR

    const int c = 1;
    //int* ptr_c = &c;      MAKE ERROR
    const int* ptr_c = &c;
    //c = 2;                MAKE ERROR
    //*ptr_c = 2;           MAKE ERROR

    cout << endl << "- A const pointer to an int ( = int* const) can not be modified to point to another direction." << endl;
    
    int d = 1;
    int e = 1;
    int* const ptr_d = &d;
    //ptr_d = &e;           MAKE ERROR

    cout << endl << "- A pointer to a const int can not be assigned to a Pointer to int." << endl;
    
    const int* ptr_x;
    //fun1(ptr_x);          MAKE ERROR
    fun2(ptr_x);
    //int * ptr_x_2 = ptr_x;   MAKE ERROR

    cout << endl << "- A const member function of a class cannot modified any other member and cannot call other non-const member functions" << endl;
    // Check Class A

    cout << endl << "- A const member function of a class cannot modified any other member and cannot call other non-const member functions" << endl;
    
    A a_non_const(33);          // object of A, any problem calling to any member, const and non-const
    a_non_const.getValue();
    a_non_const.setValue(44);

    const A a_const(33);        // const object of A
    a_const.getValue();         // calling to a const function, OK
    // a_const.setValue(44);    // MAKE ERROR: a const object can not call to non-const members
    
    return 0;
}