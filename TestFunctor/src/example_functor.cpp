/*

Testing the C++ functors or functional calls

A C++ functor (function object) is a class or struct object that can be called 
like a function.

It overloads the function-call operator () and allows us to use an object like 
a function.

*/

#include <iostream> // std::cout

// Aliases
using namespace std;


// Simple class implemented as a functor
class SimpleFunctor
{
    public:
        // Constructor
        SimpleFunctor()
        {
            cout << "SimpleFunctor created." << endl;
        }

        // Overloaded function parenthesis operator
        void operator()()
        {
            cout << "SimpleFunctor functor function called." << endl;
        }
};

// A functor that accepts args and returns a value
class IntFunctor
{
    public:
        IntFunctor()
        {
            cout << "IntFunctor created." << endl;
        }
    
        int operator()(int a, int b)
        {
            return (a+b);
        }
};

// Or the same but templated
template <typename T>
class TemplatedFunctor1
{
    public:
        TemplatedFunctor1()
        {
            cout << "TemplatedFunctor1 created." << endl;
        }

        T operator()(T a, T b)
        {
            return (a+b);
        }
};

// Or even template both, the class and the functor function
// if it makes sense ... :)
template <typename T>
class TemplatedFunctor2
{
    public:
        TemplatedFunctor2()
        {
            cout << "TemplatedFunctor2 created." << endl;
        }

        template <typename U>
        U operator()(T a, T b)
        {
            return (a+b);
        }
};


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Functors:" << endl;
    cout << "-------------------" << endl;

    cout << "" << endl;

    SimpleFunctor simple_functor;

    simple_functor();

    IntFunctor int_functor;
    cout << "Calling the int functor: " << int_functor(3,7) << endl;

    TemplatedFunctor1<int> templated1_functor;
    cout << "Calling the templated1 functor: " << templated1_functor(3,7) << endl;

    TemplatedFunctor2<int> templated2_functor;
    cout << "Calling the templated2 functor: " << templated2_functor.operator()<bool>(3,7) << endl;

    return 0;
}