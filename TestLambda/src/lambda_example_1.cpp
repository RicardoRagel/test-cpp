/*

Testing the C++ lambda features

[]       ()          ->         {} 
Capture  Parameters  ReturnType Body

They are functions directly declared "inline".

The capture field allows us to set which values from the current scope will
be visible for the lambda function and how (by value or by reference):

[ ]         // no variables defined. Attempting to use any external variables in the lambda is an error.
[ x, &y ]   // x is captured by value, y is captured by reference
[ & ]       // any external variable is implicitly captured by reference if used
[ = ]       // any external variable is implicitly captured by value if used
[ &, x ]    // x is explicitly captured by value. Other variables will be captured by reference
[ =, &z ]   // z is explicitly captured by reference. Other variables will be captured by value

*/

#include <iostream>     // std::cout
#include <functional>   // std::function
#include <vector>       // std::vector
#include <algorithm>    // std::sort, std::for_each, ...


// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Lambda:" << endl;
    cout << "------------------" << endl;

    cout << "" << endl;

    // Simple lambda function. We can assign it to a function pointer or a std function, that is the same
    //void (*lambda_fun_1)(int) = [] (int arg) { cout << "(lambda_fun_1) " << arg << ", "  << endl; };
    std::function<void(int)> lambda_fun_1 = [] (int arg) { cout << "(lambda_fun_1) " << arg << ", "  << endl; };
    lambda_fun_1(10);

    
    // Lambda function capturing a local variables
    int local_int = 20;
    //void (*lambda_fun_2)(int) = [local_int] (int arg) { cout << "(lambda_fun) " << arg << ", " << local_int << endl; };
    auto lambda_fun_2 = [local_int] (int arg) 
                        { 
                            cout << "(lambda_fun_2) " << arg << ", " << local_int << endl; 
                        };
    lambda_fun_2(10);
    // Note that both the capture and the parameters was by value. They can be captured by reference, so
    // it is faster and we can modify these values. In case you don't want to modify it, add a const keyword.

    
    // Lambda function capturing all local variables in the outside scope: [&]
    char local_char = 'x';
    auto lambda_fun_3 = [&] (int arg) 
                        { 
                            cout << "(lambda_fun_3) " << arg << ", " << local_int << ", " << local_char << endl; 
                        };
    lambda_fun_3(10);

    
    // Lambda function returning a value (-> type, ALTHOUGH IT IS NOT NECESSARY)
    auto lambda_fun_4 = [&] (int arg) -> bool
                        { 
                            cout << "(lambda_fun_3) " << arg << ", " << local_int << ", " << local_char << endl; 
                            return true;
                        };
    if(lambda_fun_4(10))
    {
        cout << "Ok!" << endl;
    }

    
    // Lambda functions are very useful to manipulate stl containers using the algorithms
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Let's set to -1 the elements between 5 and 8
    for_each(v.begin(), v.end(), [](int& elem) {
        if(elem > 5 && elem < 8)
        {
            elem = -1;
        }
    });
    
    for(auto elem : v) { cout << elem << ", "; }
    cout << endl;
    // Note: in C++ 11 capture values cannot be auto, but they can be using C++14

    // Let's remove the values equal to -1 (using remove() or remove_if())
    //vector<int>::iterator it_garbage_first_elem = remove(v.begin(), v.end(), -1);
    vector<int>::iterator it_garbage_first_elem = remove_if(v.begin(), v.end(), [](int elem){
        if(elem == -1)
            return true;
        return false;
    });
    
    for(auto elem : v) { cout << elem << ", "; }
    cout << endl;
    // Notice the size of the vector doesn't change! the last values are garbage

    // Let's remove that garbage
    v.erase(it_garbage_first_elem, v.end());

    for(auto elem : v) { cout << elem << ", "; }
    cout << endl;

    // Let's sort it from the lowe to the higher (using a binary (=2 args) functor or a lambda)
    //sort(v.begin(), v.end(), greater<int>());
    sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

    for(auto elem : v) { cout << elem << ", "; }
    cout << endl;

    return 0;
}