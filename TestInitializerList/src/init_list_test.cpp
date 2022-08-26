/*

Testing the C++ std initializer_list

std::initializer_list is a class that allows to receive an array of {n1, n2, ...}

The STD containers (vector, map, ...) have a constructor able to receive an std::initializer_list
objects.

We can also use this class to implement it by ourself.

*/

#include <iostream>     // std::cout
#include <string>       // std::string
#include <vector>       // std::vector
#include <map>          // std::map
#include <algorithm>    // std::for_each

// Aliases
using namespace std;

// Helpers declarations, defined after main()
template<typename T>
void print(vector<T> v);
template<typename T>
void print(map<string,T> m);

// A function that receives a vector<int>
// How vector<T> class has a constructor that is able to receive
// a std::initializer_list<T>, it can receive an array {n1, n2, ...}
void do_something_with(vector<int> v)
{
    print(v);
}

template <class T>
class MyOwnContainer
{
    std::vector<T>              v;
    std::map<std::string, T>    m;

    public:
        MyOwnContainer(std::initializer_list<T> l) : v(l)
        {
            for_each(l.begin(), l.end(), [this] (int elem) {
                m["The " + to_string(elem)] = elem;
            });
        }

        std::vector<T> getVector()
        {
            return v;
        }

        std::map<std::string, T> getMap()
        {
            return m;
        }
};

//// MAIN
int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Clean Test:" << endl;
    cout << "------------------" << endl;

    cout << "" << endl;

    // Simply creating a list
    std::initializer_list<int> my_init_list = {1, 2, 3, 4}; // that's ok, just a minimal array

    std::vector<int> v = {1, 2, 3, 4};  // that's ok, an inline vector initialization
    v = {1, 2, 3, 4};                   // that's also ok.
    do_something_with({1, 2, 3, 4});    // passing this array to a vector, that's ok, vector can

    // Let's use the same with our custom container
    MyOwnContainer<int> my_container = {1, 2, 3, 4};
    print(my_container.getVector());
    print(my_container.getMap());

    return 0;
}

// Helper to print vectors
template<typename T>
void print(vector<T> v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
        if(std::distance( it, v.end() ) > 1)
            cout << ", ";
    }
    cout << endl;
}

// Helper to print maps
template<typename T>
void print(map<string, T> m)
{
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ": " << it->second;
        if(std::distance( it, m.end() ) > 1)
            cout << ", ";
    }
    cout << endl;
}