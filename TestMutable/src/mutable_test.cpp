/*

Testing the C++ keyword mutable

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

class A
{
    public:
        A() : x(10), y(20)
        {

        }

        int x;
        mutable int y;
};


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Mutable:" << endl;
    cout << "--------------------" << endl;

    const A a;
    
    cout << "A constant object A: x " << a.x << " y " << a.y << endl;

    //a.x = 30; // Fail, a is a CONST object
    a.y = 30;   // OK!!, a.y is MUTABLE

    cout << "y has mutated to " << a.y << "!!!" << endl;

    int var1 = 0;
    //auto fun = [var1]() { return ++var1; }; // ERROR: Captured variables by value can not be modified

    // but.... mutable!
    auto fun = [var1]() mutable { return ++var1; };
    cout << "Using mutable with lambda: " << fun() << endl;

    return 0;
}