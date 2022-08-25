#include <iostream>
#include <iomanip>  // std::setprecision()

using namespace std;

/* 
    Easy Example: Just a variable that we can template
*/

// The PI number templated, so we can request it any variable type
template<typename T>
T pi = T(3.141592653589793238462643383279502884197);

// Specialization for string
template<>
string pi<string> = "3.141592653589793238462643383279502884197";


/*
    Complex example: Let's assign to this variable a lambda funtion
    so we can call this lambda function with the same typename
*/
template<typename T>
auto add = [](const T &a, const T &b) { return a + b; };


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Templated Variables:" << endl;
    cout << "--------------------------------" << endl << endl;

    cout << "Easy Example:" << endl << endl;
    cout << "Pi as string:\t"    << setprecision(20) << pi<string> << endl;
    cout << "Pi as double:\t"    << setprecision(20) << pi<double> << endl;
    cout << "Pi as float:\t"     << setprecision(20) << pi<float> << endl;
    cout << "Pi as integer:\t"   << setprecision(20) << pi<int> << endl;

    cout << endl << "Complex Example:"<< endl;
    cout << add<int>(3.14, 2.99) << endl;
    cout << add<int>('a', 'c') << endl;

    return 0;
}