/*

Testing the C++ function pointers

Function pointers as exactly that, a pointer to another function that can be used to call that function.

A func(B b)
{

}

A (*ptr) (B) = fun;

The main purpose of a function pointer is to be used as an argument of another function, so we can pass a 
function to be called from other function / class member function / ...

C caller(A (*ptr) (B))
{
    ptr();
}

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

// Simple function
bool callback(string str)
{
    if(str != "")
    {
        cout << "(callback) " << str << endl;
        return true;
    }

    return false;
}

// A function that receives a pointer to another function
void callback_caller(bool (*f_ptr)(string))
{
    f_ptr("Calling the function through a pointer from another function");
}

// A class that receives a function to be used by one of his methods
class A
{
    public: 
        // Constructor: receives a pointer to a function and save it in a member pointer variable
        A(bool (*f_ptr)(string))
        {
            f_ptr_ = f_ptr;
        }

        bool (*f_ptr_)(string);

        void caller()
        {
            f_ptr_("hello from class A!");
        }
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Function Pointers:" << endl;
    cout << "------------------------------" << endl;

    // Creating a pointer to the function and calling it
    bool (*f_ptr)(string) = callback;
    bool result = f_ptr("Calling the function through a pointer from the main function");
    cout << "(main) Result: " << result << endl;
    cout << "" << endl;

    // Calling to a function through another function
    callback_caller(callback);
    cout << "" << endl;

    // Creating a class that receives a function and call it from a member function
    A a(callback);
    a.caller();
    cout << "" << endl;

    return 0;
}