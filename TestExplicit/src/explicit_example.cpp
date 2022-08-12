/*

Testing the explicit keyword

Explicit is used to force the programers to use a specific constructor of a class.

In other words, it forces the compiler to use this exact constructor, avoiding implicit
conversions.

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

class Foo
{
  public:
    // single parameter constructor, can be used as an implicit conversion
    Foo (int num) : m_num (num)
    {
        cout << "Non-explicit constructor receiving an Integer value" << endl;
    }

    // explicit constructor, it can NOT be used as an implicit conversion
    explicit Foo (double num) : m_double (num)
    {
        cout << "Explicit constructor receiving a Double value" << endl;
    }

    // explicit constructor, it can NOT be used as an implicit conversion
    explicit Foo (string str) : m_str (str)
    {
        cout << "Explicit constructor receiving a String value" << endl;
    }

  private:
    int m_num;
    double m_double;
    string m_str;
};


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Explicit:" << endl;
    cout << "---------------------" << endl;

    // This is possible due to it is not explicit
    Foo foo_1 = 4;

    // Although this one should call to the constructor that receives a Double value,
    // it will call to the Integer one due to the double one is explicit. This is an
    // non-expected implicit conversion
    Foo foo_2 = 4.4;
    // To call the correct one (the double one), the explicit conversion will be used
    Foo foo_3(4.4);

    // In the previous case, int to double could be done by the implicit conversion. 
    // However, this is not the case for the constructor that receives a String
    //Foo foo_4 = "Hey";    // MAKE ERROR
    Foo foo_5("Hey");

    cout << "" << endl;

    return 0;
}