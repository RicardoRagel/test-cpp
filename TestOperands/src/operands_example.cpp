/*

Testing the C++ Operands

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Operands:" << endl;
    cout << "--------------------" << endl;

    cout << 25u - 50 << endl;

/*
In C++, if the types of two operands differ from one another, then the operand with the “lower type” will be promoted to the type of the “higher type” operand, using the following type hierarchy (listed here from highest type to lowest type): long double, double, float, unsigned long int, long int, unsigned int, int (lowest).

So when the two operands are, as in our example, 25u (unsigned int) and 50 (int), the 50 is promoted to also being an unsigned integer (i.e., 50u), because it uint is higher than int.

Check table: https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm
*/
    cout << 25u - 50 << endl;

    int a = 25u - 50;

    cout << a << endl;

    return 0;
}