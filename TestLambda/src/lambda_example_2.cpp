/*

Testing the C++ lambda features -> Capture values

*/

#include <iostream> // std::cout
#include <vector>
#include <algorithm>

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Lambda:" << endl;
    cout << "------------------" << endl;

    cout << "" << endl;

    int x = 1;
    static int y = 2;

    auto fun = [x](){
        cout << "I have captured x: " << x << " but I also can see y: " << y 
             << " because it is static!!!" << endl;
    };

    fun();

    return 0;
}