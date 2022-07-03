/*

Testing the C++ Operands

*/

#include <iostream> // std::cout

// Aliases
using namespace std;


class A
{
    public:
        int i;

        A(int i)
        {
            //i = i; // FUCK... setting arg i to its own value
            this->i = i;
        }
};


class B 
{ 
   public: 
      static int x; 
      int i; 

      B() 
      {
         i = ++x;
      }
};
int B::x; // by default: 0

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Random Tests:" << endl;
    cout << "--------------------" << endl;

    A a(5);
    cout << a.i << endl;

    B b1, b2, b3;
    cout << b1.i << ", " << b2.i << ", " << b3.i << ", " << b1.x << ", " << B::x << endl; 

    int n = 20;
    float c = 5;
    float b = 2;
    cout << n % 20 + c * --b << endl;

    cout << 20 % 7 << endl; // 7*2 = 14 --> 20 - 14 = 6, the rest of the division

    // cout << 20.0 % 7.0;  // MAKE ERROR: % can be used only with integers

    cout << 'A' + 'A' << endl;
    char letter = 'A' + 'A'; // char goes from -127 to 128
    cout << int(letter) << endl;

    int res = 9 % 7;
    cout << res << endl;
    res = 3 * 9 % 7;
    cout << res << endl; // *, / and % has the same precedence because they are "interchable", is the same first apply the % that first apply the *

    return 0;
}