#include "TestCpp.hpp"

using namespace std;

//! No variables initialisation
TestCpp::TestCpp()
{
    printf("(TestCpp) Default Constructor\n");
}

//! Init variables
//!     @param value Value for the private data
TestCpp::TestCpp(int value)
{
    printf("(TestCpp) Constructor with arg: %d\n", value);
    private_data_ = value;
}

//! Get the value of the private data
//!     @return Value of the private data
int TestCpp::getPrivateData()
{
    return private_data_;
}

//! No variables initialisation
Derived::Derived()
{
    printf("(Derived) Default Constructor\n");
}

//! Init variables
//!     @param value Value for the public data. It will also init TestCpp using the same value
Derived::Derived(int value):TestCpp(value)
{
    printf("(Derived) Constructor with arg: %d\n", value);
    public_data_ = value;
}

//! No variables initialisation
Derived2::Derived2()
{
    printf("(Derived2) Default Constructor\n");
}

//! Init variables
//!     @param value Value for the init Derived base class
Derived2::Derived2(int value):Derived(value)
{
    printf("(Derived2) Constructor with arg: %d\n", value);
}