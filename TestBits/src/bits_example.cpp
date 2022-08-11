/*

Testing bitwise operators

*/

#include <iostream> // std::cout
#include <bitset>   // std::bitset

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test BitSet:" << endl;
    cout << "------------------" << endl;

    cout << "Class bitset allows us to print any variable in binary just providing the number of bits" << endl;
    uint8_t u8 = 3; // 00000011
    cout << "For example, an uint8_t containing the number 3: " << bitset<8>(u8) << endl << endl;

    // Testing binary operators
    uint8_t a = 10; // 00001010
    uint8_t b = 2;  // 00000010
    cout << "Testing binary operations for " << (int)a << " [" << bitset<8>(a) << "]" << " and " << (int)b << " [" << bitset<8>(b) << "]" << endl;
    cout << "Binary 'and'    is &:  " << bitset<8>( a & b ) << endl;
    cout << "Binary 'or'     is |:  " << bitset<8>( a | b ) << endl;
    cout << "Binary 'xor'    is ^:  " << bitset<8>( a ^ b ) << endl;
    cout << "Binary 'Lshift' is <<: " << bitset<8>( a << 1 ) << endl;
    cout << "Binary 'Rshift' is >>: " << bitset<8>( a >> 1 ) << endl;
    cout << "Binary '!'      is ~:  " << bitset<8>( ~a ) << endl;

    return 0;
}