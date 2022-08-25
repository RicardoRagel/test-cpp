/*

Testing the C++ 11 constexpr

The main idea is a performance improvement of programs by doing computations 
at compile time rather than run time.

constexpr specifies that the value of an object or a function can be evaluated 
at compile-time and the expression can be used in other constant expressions

It removes the function calls as it evaluates the code/expressions in compile time!!!

*/

#include <iostream> // std::cout

// Aliases
using namespace std;


/*
    Example 1: Using a function that returns a constexpr, so the function
    will be replaced by the result value in compile-time, saving time in the execution
*/
constexpr int function(int x, int y)
{
    return x * y;
}

/*
    Example 2: Using in the constructor and members of a class. We get the same advantages, 
    but we will have to take into account that:
    * The object have be created only using literals parameters
    * All the data members must be initialized in that constructor using only literals
    * The body of the constructor must be empty
*/
class QuickInitClass
{
    int m_a, m_b, m_c;

    public:
        constexpr QuickInitClass(int a, int b) : m_a (a), m_b (b), m_c(33)
        {
        }

        constexpr int getProduct()
        {
            return m_a * m_b;
        }
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Constexpr:" << endl;
    cout << "----------------------" << endl;

/*
    Example 1
*/
    constexpr int value1 = function(10, 5);   // OK, it is possible it is computed at compile-time

    int a = 10;
    int b = 5;
    //constexpr int value2 = function(a, b);    // FAILS! It cannot be computed at compile-time

    // We can use the function as:
    int value2 = function(10, 5);
    int value3 = function(a, b);
    // but then, actually we are not using the constexpr advantages, in other words,
    // the result is not computed in compile-time, so we are not saving time in run-time.

    // Or we can use variables always that these variables are also constexpr
    constexpr int ca = 10;
    constexpr int cb = 5;
    constexpr int value4 = function(ca, cb);

/*
    Example 2
*/
    constexpr QuickInitClass obj1(4,5);
    constexpr int obj1_product = obj1.getProduct();
    cout << "Obj1 product: " << obj1_product << endl;

    //constexpr QuickInitClass obj2(a,b); // FAILS

    cout << "" << endl;

    return 0;
}