/*

Testing the C++ 11 (and later) auto keyword for Type Inference

Type Inference refers to automatic deduction of the data type of 
an expression in a programming language. After C++ 11, many keywords 
are included which allows a programmer to leave the type deduction to 
the compiler itself. 

With type inference capabilities, we can spend less time having to write 
out things the compiler already knows. As all the types are deduced in 
the compiler phase only, the time for compilation increases slightly but 
it does not affect the run time of the program.

Two main features:

    * auto keyword: It infers the type from the initialization of the object
                    or the return value of a function. So we can declare the
                    type of an object as "auto".

    * decltype():   It inspects the declared type of an expression extracting
                    the final type


*/

#include <iostream> // std::cout
#include <vector>

// Aliases
using namespace std;


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Auto Inference:" << endl;
    cout << "---------------------------" << endl;
    cout << "" << endl;

    // This is possible, but it is implicitly by the literal number, not
    // recommended for this kind of things
    auto x = 1.0;

    // The idea is use it with more complex expresion that can be inferences
    // in the initialization
    vector<int> v = {1, 2, 3, 4};
    // Compiler knows what v.begin() returns
    for(auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Hey! We cannot do this, it is a type, not a rvalue
    //cout << decltype(1.0 + 2) << endl;
    // To check the type, you can use typeid
    cout << typeid(1.0 + 2).name() << endl;
    // i: integer, f: float, d: double, ...

    // Using the type that declatype() returns:
    int integer = 2;
    float floating = 1.0;
    decltype(integer + floating) sum_result;
    cout << typeid(sum_result).name() << endl;

    int i = 1;
    float j = 10.0;
    decltype(i) k = i * 10.0;
    cout << k << endl;

    // Note: Decltype gives the type information at compile time while typeid gives at runtime.

    return 0;
}