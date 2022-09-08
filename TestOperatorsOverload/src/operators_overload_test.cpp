/*

Testing operators overload

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

class A
{
    public:
        A(int x): m_x(x) 
        {

        };

        // Overloading operators
        A operator+ (const int x) const
        {
            A a(x + m_x);
            return a;
        };

        // Overloading type casting operators
        operator bool() const
        {
            return m_x > 0 ? true : false;
        };

    
    // private:
        int m_x;

};


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Operators Overload Test:" << endl;
    cout << "-------------------------------" << endl;

    cout << "" << endl;

    A a(33);

    A b = a + 3;

    cout << "Using + operator: " << b.m_x << endl;

    cout << "Using operator bool(): " << bool(a) << endl;

    return 0;
}