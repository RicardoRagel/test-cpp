/*

Testing the C++ Keyword: static

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// A function with a static variable
void fun(int arg)
{
    static int fun_var;

    cout << endl << "(fun) Value of static var before set to arg: " << fun_var << endl;

    fun_var = arg;

    cout << "(fun) Value of static var after set to arg: " << fun_var << endl;
}

// A class with a static variable
class A
{
    public: 
        A()
        {
            cout << "(A) Constructor" << endl;
        };

        ~A()
        {
            cout << "(A) Destructor" << endl;
        };

        static int var;

        void print_var()
        {
            cout << "(A) var: " << var << endl;
        };

        static int get_var()
        {
            return var;
        }

};
int A::var = 0; // It is necessary to initialize it

// A derivated class from a class with a static variable
class B : public A
{
    public: 
        B()
        {
            cout << "(B) Constructor" << endl;
        };

        ~B()
        {
            cout << "(B) Destructor" << endl;
        };
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Static:" << endl;
    cout << "--------------------" << endl;

    cout << endl << "* The Keyword static doesn't mean that the variable cannot be modified:" << endl;

    static int i = 1;
    cout << "i: " << i << endl;
    i = 2;
    cout << "i: " << i << endl;

    cout << endl << "* The Keyword static makes that a variable in a function keeps the value:" << endl;
    fun(1);
    fun(2);

    cout << endl << "* The Keyword static makes that a variable in a class keeps the value, being the same for all the objects if this class:" << endl;

    A a1;
    a1.var = 33;
    A a2;
    a2.print_var();
    B b1;
    b1.print_var();

    cout << endl << "* The Keyword static makes that a function in a class be accessible without creating an object:" << endl;
    cout << "Accessing directly to the static member var using a static member function: " << A::get_var() << endl;

    return 0;
}