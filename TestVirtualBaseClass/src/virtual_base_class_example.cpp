/*

Testing the C++ Virtual Base Classes

They solve the problem of multiple inheritance.

For example, when:

A -> B -> D
A -> C -> D

So D is inheriting twice the Base Class A. It will through a compiler error because
D has 2 copies of A, and that's not possible.

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

class A {
  public:
    int number;
    A() // constructor
    {
      number = 1;
    }
};

// class B: public A {          // MAKE ERROR
class B: public virtual A {
  public:
    B()
    {
        number = 2;
    }
};

// class C: public A {          // MAKE ERROR
class C: public virtual A {
  public:
    C()
    {
        number = 3;
    }
};

class D: public B, public C {
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Virtual Base Class:" << endl;
    cout << "-------------------------------" << endl;

    D d;
    cout << d.number << endl << endl;

    cout << "The result is 3 (the value set in the constructor of the class C) because of D first inherits from B and second from C, so the constructors are call, first A, later B and later C." << endl;

    cout << "" << endl;

    return 0;
}