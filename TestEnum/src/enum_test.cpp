/*

Testing Enums

They are directly in the Global scope!!!

*/

#include <iostream> // std::cout

// Aliases
using namespace std;

enum BasicColor : uint8_t
{
    RED = 0,
    GREEN,
    BLUE
};

enum Color : uint8_t
{
    YELLOW = 4,
    BROWN,
    ORANGE
};

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Enums:" << endl;
    cout << "-----------------" << endl;

    cout << "Basic Colors: " << RED << ", " << GREEN << ", " << BLUE << ", " << endl;
    cout << "Colors: " << YELLOW << ", " << BROWN << ", " << ORANGE << ", " << endl;

    cout << "" << endl;

    return 0;
}