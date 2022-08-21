/*

Testing the C++ std::function<> type and std::bind() function 

*/

#include <iostream> // std::cout
#include <functional> // std::function

// Aliases
using namespace std;

using namespace std::placeholders;


// A class
class A
{
    public:
        float method(int16_t a, int16_t b)
        {
            return a*b*1.1;
        }
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test function and bind in a class:" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "" << endl;

    // Getting a function pointer to the class method (with the same args, so using _1 and _2)
    // Take note that it is necessary to pass the class method reference and the object reference separately.
    A a;
    std::function<float(int16_t, int16_t)> methodPtr = std::bind(&A::method, &a, _1, _2);

    cout << "Testing member function pointer: " << methodPtr(2,3) << endl;

    // When is it useful? For example, when we have to pass to a library function a callback function that is a member of our class.
    return 0;
}