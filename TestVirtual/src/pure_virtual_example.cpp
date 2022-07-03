/*

Testing the C++ Keyword: virtual

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// Abstract class: A class with a pure virtual function
class Abstract
{
    public: 
        Abstract()
        {
            cout << "(Abstract) Constructor" << endl;
        };

        ~Abstract()
        {
            cout << "(Abstract) Destructor" << endl;
        };

        void normal_fun()
        {
            cout << "(Abstract) - Normal function" << endl;
        }

        virtual void pure_virtual_fun() = 0;
};

// A derived class from the Abstract class
class B : public Abstract
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

        void pure_virtual_fun()
        {
            cout << "(B) Defining pure virtual method" << endl;
        };
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Pure Virtual:" << endl;
    cout << "-------------------------" << endl;

    cout << endl << "* It is not possible to create an object of an abstract class" << endl;
    // Abstract a;              // MAKE ERROR
    B b;
    b.pure_virtual_fun();
    B* ptr_b = &b;
    ptr_b->pure_virtual_fun();

    return 0;
}