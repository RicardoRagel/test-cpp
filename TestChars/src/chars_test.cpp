/*

Testing the different char types

*/

#include <iostream> // std::cout
#include <string.h>

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Chars Test:" << endl;
    cout << "------------------" << endl;
    cout << "" << endl;

    cout << "char:\t\t"      << sizeof(char)     << " bytes" << endl;
    cout << "char16_t:\t"    << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t:\t"    << sizeof(char32_t) << " bytes" << endl;
    cout << "wchar_t:\t"     << sizeof(wchar_t)  << " bytes" << endl;

    cout << "string:\t\t\t"               << sizeof(std::string("A"))  << " bytes" << endl;
    cout << "string character num:\t"   << std::string("A").size()     << " characters" << endl;
    cout << "string character:\t"     << sizeof(std::string::value_type) << " bytes" << endl;
    
    cout << "u16string:\t\t"              << sizeof(std::u16string(u"A"))  << " bytes" << endl;
    cout << "u16string character num:"  << std::u16string(u"A").size()     << " characters" << endl;
    cout << "u16string character:\t"      << sizeof(std::u16string::value_type) << " bytes" << endl;
    
    cout << "int:\t\t"    << sizeof(int)  << " bytes" << endl;
    cout << "int8_t:\t\t" << sizeof(int8_t)  << " bytes" << endl;
    cout << "int16_t:\t"  << sizeof(int16_t)  << " bytes" << endl;
    cout << "int32_t:\t"  << sizeof(int32_t)  << " bytes" << endl;
    cout << "int32_t:\t"  << sizeof(int32_t)  << " bytes" << endl;
    cout << "int64_t:\t"  << sizeof(int64_t)  << " bytes" << endl;
    
    return 0;
}