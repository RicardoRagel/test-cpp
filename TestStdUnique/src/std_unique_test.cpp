/*

Testing the C++ std::unique function

It simply removes duplicated values in a row in a container. However, it doesn't change the
container size, so the elements at the end will be "garbage" with the same values that these
elements have before the operation.

To remove then, you can use the result of this operation, that is an iterator pointing to
the first of these elements.
*/

#include <iostream> // std::cout
#include <vector>
#include <algorithm>

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test std::unique:" << endl;
    cout << "------------------------" << endl;

    vector<int> v {0,0,0,1,1,1,3,3,3,4,4,4,4,4,4,4,4,4,5,5,32,14,20,1,1,2,2};

    cout << "vector of " << v.size() << " elements:" << endl;
    for(auto value : v)
    {
        cout << value << ", ";
    }
    cout << "" << endl;

    auto it = unique(v.begin(), v.end());

    cout << "vector of " << v.size() << " elements:" << endl;
    for(auto value : v)
    {
        cout << value << ", ";
    }
    cout << "" << endl;

    cout << "Iter pos: " << *it << endl; 
    cout << "Iter pos next: " << *(it+1) << endl; 

    v.erase(it, v.end());
    cout << "vector of " << v.size() << " elements:" << endl;
    for(auto value : v)
    {
        cout << value << ", ";
    }
    cout << "" << endl;

    return 0;
}