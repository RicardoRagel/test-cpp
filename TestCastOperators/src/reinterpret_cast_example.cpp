/*

Testing C++ Reinterpret Casting

reinterpret_cast converts any pointer type to any other pointer type, 
even of unrelated classes. The operation result is a simple binary copy 
of the value from one pointer to the other. All pointer conversions are 
allowed: neither the content pointed nor the pointer type itself is checked.

in the following example we will check how the data is copied (member variables)
but the interface (member functions) is the one of the pointer 
*/

#include <iostream> // std::cout

// Aliases
using namespace std;

class Base1
{ 
    public:
        Base1(int _a, float _b) : a (_a), b (_b) {}
        
        int a;
        float b;
        string str = "Base1";
        
        void sayHello() { cout << "(Base1) Hello, my string is "  << str << " and my double " << b << endl; }
};

class Base2
{ 
    public:
        Base2(int _x, float _y) : x (_x), y (_y) {}
        int x;
        float y = -1.001;
        string str = "Base2";

        void sayHello() { cout << "(Base2) Hello, my string is "  << str << " and my double " << y << endl; }
};

struct S
{
    int s1;
    float s2;
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Reinterpret Casting Test:" << endl;
    cout << "--------------------------------" << endl;

    Base1 b1(3, 33.3);

    Base2* b2 = reinterpret_cast<Base2*>(&b1); // it is not allowed by dynamic_cast
    cout << "-- Base 2 pointer to Base 1 object: " << endl;
    cout << "member variable: " << b2->x << endl; // b1::a has been binary-copied to b2::x
    cout << "member function: "; 
    b2->sayHello();
    cout << endl;

    // Let's do the same to save b1::a and b1::b in a struct S
    S *s;
    s = reinterpret_cast<S*>(&b1);
    cout << "-- Struct S pointer to Base 1 object: " << endl;
    cout << "member variables: " << s->s1 << ", " << s->s2 << endl;

    cout << "" << endl;
 
    return 0;
}