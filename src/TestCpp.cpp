#include "TestCpp.hpp"

using namespace std;

TestCpp::TestCpp()
{
    printf("(TestCpp) Default Constructor\n");
}

TestCpp::TestCpp(int value)
{
    printf("(TestCpp) Constructor with arg: %d\n", value);
    private_data_ = value;
}

int TestCpp::getPrivateData()
{
    return private_data_;
}

Derived::Derived()
{
    printf("(Derived) Default Constructor\n");
}

Derived::Derived(int value):TestCpp(value)
{
    printf("(Derived) Constructor with arg: %d\n", value);
    public_data_ = value;
}

Derived2::Derived2()
{
    printf("(Derived2) Default Constructor\n");
}

Derived2::Derived2(int value):Derived(value)
{
    printf("(Derived2) Constructor with arg: %d\n", value);
}