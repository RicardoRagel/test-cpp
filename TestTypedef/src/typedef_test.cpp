/*

Testing the C++ typedef keyword

*/

#include <iostream> // std::cout
#include <map>

// Aliases
using namespace std;

// Type Definitions
typedef std::map<int16_t, string> MyMap;
typedef struct 
{
    int16_t id;
    string name; 
} MyStruct;

// A bit more complex: defining a pointer to a function
typedef int16_t ( * MyFnPtr ) (int16_t); 

// simple function to be used by the previous pointer
int16_t fun (int16_t a)
{
    return a;
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Typedef:" << endl;
    cout << "-------------------" << endl;

    cout << "" << endl;

    MyMap my_map =  {
                        {0, "firts"},
                        {1, "second"},
                        {2, "third"},
                    };
    cout << "MyMap[2] = " << my_map[2] << endl;

    MyStruct my_struct {33, "Good number"};
    cout << "MyStruct.name = " << my_struct.name << endl;     

    MyFnPtr my_fn_ptr = fun; // or &fun; In case of functions pointer they are identical.
    cout << "MyFnPtr(69) = " << my_fn_ptr(69) << endl; // Or the identical result:
    // cout << "MyFnPtr(69) = " << (*my_fn_ptr)(69) << endl;     

    return 0;
}