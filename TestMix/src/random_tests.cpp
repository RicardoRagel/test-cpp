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
            //i = i; // WRONG... setting arg i to its own value
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

    ////////////////////////////////////////////////////////////

    B b1, b2, b3;
    cout << b1.i << ", " << b2.i << ", " << b3.i << ", " << b1.x << ", " << B::x << endl; 

    ////////////////////////////////////////////////////////////

    int n = 20;
    float c = 5;
    float b = 2;
    cout << n % 20 + c * --b << endl;

    cout << 20 % 7 << endl; // 7*2 = 14 --> 20 - 14 = 6, the rest of the division

    // cout << 20.0 % 7.0;  // MAKE ERROR: % can be used only with integers

    ////////////////////////////////////////////////////////////

    cout << 'A' + 'A' << endl;
    char letter = 'A' + 'A'; // char goes from -127 to 128
    cout << int(letter) << endl;

    ////////////////////////////////////////////////////////////

    int res = 9 % 7;
    cout << res << endl;
    res = 3 * 9 % 7;
    cout << res << endl; // *, / and % has the same precedence because they are "interchable", is the same first apply the % that first apply the *
    
    ////////////////////////////////////////////////////////////

    // Testing signed and unsigned conversion
    uint8_t u8 = 2;
    int8_t s8 = -44;
    int8_t sr = u8 + s8; // unsigned + signed is always promoted to signed
    printf("Result as signed:   %hhd\n", sr);
    //printf("Result as unsigned: %hhu\n", sr);

    uint8_t ur = u8 + s8; // unsigned + signed is always promoted to signed
    //printf("Result as signed:   %hhd\n", ur);
    printf("Result as unsigned: %hhu\n", ur);

    cout << "" << endl;

    ////////////////////////////////////////////////////////////

    string str1 = "This is a test";
    string str2 = "This is a test";
    if(str1.compare(str2) == 0)
    {
        cout << "Strings are equal" << endl;
    }

    ////////////////////////////////////////////////////////////

    char carray[] = "Hello";

    cout << carray << endl;
    cout << carray[2] << endl;

    char16_t c16array[] = u"Hello";
    
    cout << c16array << endl;
    cout << c16array[2] << endl;

    char32_t c32array[] = U"Hello";
    
    cout << c32array << endl;
    cout << c32array[2] << endl;
    
    return 0;
}