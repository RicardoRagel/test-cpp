/*

Testing the C++ Keyword: friend

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// A class with a friend function (that is not declared inside it)
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

    private:

        int var = 33;

        friend void print_var(A a);

        friend class B;
};

// A standalone function
void print_var(A a)
{
    cout << "(print_var) Accessing private var: " << a.var << endl;
};

// A class B with a member variable A, being B friend of A
class B
{
    public:
        B()
        {
            
        };

        void access_private_A_data()
        {
            cout << "(B) Accessing private var: " << a.var << endl;
        }

    private:
        A a;    
};


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Friend:" << endl;
    cout << "--------------------" << endl;

    cout << endl << "* The Keyword friend allows that an external function can access ALL the members of a class:" << endl;
    A a1;
    print_var(a1);

    cout << endl << "* The Keyword friend allows that an class can access ALL the members of another class:" << endl;
    B b1;
    b1.access_private_A_data();

    return 0;
}