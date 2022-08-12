/*

Testing C++ Dynamic Casting

It is used only with pointers and references objects. Its purpose is to ensure 
that the result of the type conversion is a valid complete object of the requested 
class.

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

class Base 
{ 
    virtual void dummy() {} 
};

class Derived: public Base 
{ 
    int a;

    void dummy() {}
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Dynamic Casting Test:" << endl;
    cout << "----------------------------" << endl;

    cout << "" << endl;

    Base * pbd = new Derived;
    Base * pbb = new Base;
    
    Derived * pd;

    cout << "-- Casting a Base pointer to a DERIVED object to a Derived pointer" << endl;
    pd = dynamic_cast<Derived*>(pbd);
    if (pd==0) 
        cout << "Null pointer on first type-cast!" << endl;
    else
        cout << "OK!" << endl;

    cout << "-- Casting a Base pointer to a BASE object to a Derived pointer" << endl;
    pd = dynamic_cast<Derived*>(pbb);
    if (pd==0) 
        cout << "Null pointer on second type-cast!" << endl;
    else
        cout << "OK!" << endl;
    
    cout << "" << endl;

    return 0;
}