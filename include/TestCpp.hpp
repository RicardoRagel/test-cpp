#ifndef TESTCPP_H
#define TESTCPP_H

#include <iostream>

class TestCpp
{
    public:        
        // Constructors
        TestCpp();
        TestCpp(int value); 

        // Destructor
        ~TestCpp() = default;

        int public_data_;

    private:
        int private_data_;
};

class Derived : public TestCpp
{
    public:
        // Constructor
        Derived();
        Derived(int value);
}; 

class Derived2 : public Derived
{
    public:
        // Constructor
        Derived2();
        Derived2(int value);

        // Overload operator < to use Derived2 as a key in a std::set
        bool operator< (const Derived2 &other_derived2) const
        {
            return public_data_ < other_derived2.public_data_; 
        }
}; 

#endif