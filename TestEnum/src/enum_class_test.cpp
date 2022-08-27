/*

Testing Class Enums

They are scoped!

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

enum class BasicColor : uint8_t
{
    RED = 0,
    GREEN,
    BLUE
};

enum class Color : uint8_t
{
    YELLOW = 4,
    BROWN,
    ORANGE
};

// Overload cout << for these classes
std::ostream& operator << (std::ostream& os, const BasicColor& obj)
{
   os << static_cast<uint16_t>(obj); 
   // Although it is uint8_t, to print it correctly, it is necessary to cast it to uint16_t for cout
   return os;
}
std::ostream& operator << (std::ostream& os, const Color& obj)
{
   os << static_cast<uint16_t>(obj);

   return os;
}


int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Enum Class:" << endl;
    cout << "-----------------------" << endl;

    cout << "Basic Colors: " << BasicColor::RED << ", " << BasicColor::GREEN << ", " << BasicColor::BLUE << ", " << endl;
    cout << "Colors: " << Color::YELLOW << ", " << Color::BROWN << ", " << Color::ORANGE << ", " << endl;

    cout << "" << endl;

    return 0;
}