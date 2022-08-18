/*

Testing the C++ functors of the standard library
together with the STL containers and algorithms

*/

#include <iostream>     // std::cout
#include <functional>   // std predefined functors, like greater<>()
#include <vector>       // STL containers, like std::vector
#include <algorithm>    // STL algorithms, like std::sort()
// Aliases
using namespace std;

// A functor that accepts args and returns a value
class Sum
{
    public:
        void operator()(int &a)
        {
            a = a + 1;
            sum += a;
        }

        int sum = 0;
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test STD Functors and STL:" << endl;
    cout << "---------------------------------" << endl;
    cout << "" << endl;


    //------------------------------------------------------------------ TEST SORT()
    cout << "-- sort():" << endl;

    // A STL container
    vector<int> v = {2, 1, 5, 4, 3};

    // A STL algorithm using a STD functor to sort a STD container 
    sort(v.begin(), v.end(), greater<int>());
    
    // std::sort has ordered the elements
    cout << "v: ";
    for(auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;

    //------------------------------------------------------------------ TEST FOR_EACH()
    cout << "-- for_each():" << endl;
    // Another example of usage of the STL algorithms but using a 
    // lambda function directly (it could be also a simple function)
    for_each(v.begin(), v.end(), [](int &n) { n = n + 1; });

    // std::sort has ordered the elements
    cout << "v: ";
    for(auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;

    // Let's do it with a custom functor that will also return us the accumulated sum,
    // due to the functor object is returned by for_each
    Sum s = for_each(v.begin(), v.end(), Sum());
    
    cout << "v: ";
    for(auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
    cout << "And the total is: " << s.sum << endl;

    //------------------------------------------------------------------ TEST TRANSFORM()
    cout << "-- Transform():" << endl;
    // Let's do something using other algorithm: transform
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5};
    // ARGS:   Input1.first   Input1.last  Input2.first   Output.first   Function to call
    transform( v1.begin(),    v1.end(),    v2.begin(),    v1.begin(),    [](int &n1, int &n2) {
            return n1 + n2; 
        }
    );
    
    cout << "v1: ";
    for(auto i : v1)
    {
        cout << i << ", ";
    }
    cout << endl;

    cout << "v2: ";
    for(auto i : v2)
    {
        cout << i << ", ";
    }
    cout << endl;

     //------------------------------------------------------------------ TEST TRANSFORM() IN THE OVERLOADED FORM
    cout << "-- Transform() overloaded:" << endl;
    // Let's do the same, but using the overloaded form of transform, only one input
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4; // NOT INITIALIZED.... So we can use v4.begin() as the output ... Let's use std::back_inserter
    // ARGS:   Input1.first   Input1.last  Output.first   Function to call
    transform( v3.begin(),    v3.end(),    back_inserter(v4),    [](int &n1) {
            return n1 + 10; 
        }
    );
    
    cout << "v3: ";
    for(auto i : v3)
    {
        cout << i << ", ";
    }
    cout << endl;

    cout << "v4: ";
    for(auto i : v4)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}