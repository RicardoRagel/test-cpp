/*

Testing the C++ Keyword: virtual

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// A class with a virtual function
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
            x_ = a.x_;
        };

        ~A()
        {
            cout << "(A) Destructor" << endl;
        };

        void normal_fun()
        {
            cout << "(A) - Normal function" << endl;
        }

        virtual void virtual_fun()
        {
            cout << "(A) - Virtual function" << endl;
        }

        int x_ = 1;
};

// A derived class from a class with a static variable
class B : public A
{
    public: 
        B()
        {
            cout << "(B) Constructor" << endl;
        };

        B(const B &b)
        {
            cout << "(B) Copy Constructor" << endl;
        };

        ~B()
        {
            cout << "(B) Destructor" << endl;
        };

        void normal_fun()
        {
            cout << "(B) - Normal function" << endl;
        }

        void virtual_fun()
        {
            cout << "(B) - Virtual function" << endl;
        }

        void new_fun()
        {
            cout << "(B) - New function" << endl;
        }

        int y_ = 2;
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Virtual:" << endl;
    cout << "--------------------" << endl;

    // cout << endl << "* Base class and Derived class will call they our (override) functions" << endl;
    // A a;
    // a.normal_fun();
    // B b;
    // b.normal_fun();

    // cout << endl << "* Derived class can be saved in a Base class variable, but then the function called will be the base one due to the type of the variable:" << endl;
    // B b;
    // A a = b;
    // a.normal_fun();
    
    //b.new_fun();  OK
    //a.new_fun();  MAKE ERROR: although we copied B b into A a, only the A members has been copied

    // cout << endl << "* To make sure the derived class function is called although the object type is the Base one, we can add the keyword virtual to the base class function:" << endl;
    // B b;
    // A a = b;
    // a.normal_fun();
    // a.virtual_fun();

    //cout << endl << "* DOES IT NOT WORK? No, it has not worked because of the type of the variable is A, the base one. To make it works, we cannot use variables, we must use pointers:" << endl;
    
    // B b;
    // A* a = &b; 
    // or 
    A* a = new B();
    a->normal_fun();
    a->virtual_fun(); // This correctly calls to the derived one!
    delete a;
    cout << endl << "Notice also how when we delete the pointer, it only calls to the pointer type destructor. Why? Let's say that the destructor is not virtual, so it calls to the pointer type method" << endl;

    return 0;
}