#ifndef TESTCPP_H
#define TESTCPP_H

#include <iostream>

//! TestCpp Class
/** Base class with one public data member and one private data member and its getter function */
class TestCpp
{
    public:
        //! Default Constructor
        TestCpp();
        //! Constructor
        TestCpp(int value); 

        //! Destructor
        ~TestCpp() = default;

        //! Private data Getter
        int getPrivateData();
    
    public:
        int public_data_;   //!< A simple integer public data
    private:
        int private_data_;  //!< A simple integer private data
};

//! Derived Cpp Class
/** Class derived from TestCpp. It passes the received value to the TestCpp base class and set it to the public data */
class Derived : public TestCpp
{
    public:
        //! Default Constructor
        Derived();
        //! Constructor
        Derived(int value);
}; 

//! Another Derived Cpp Class
/** Class derived from Derived. It passes the received value to the Derived base class and set it to the public data */
class Derived2 : public Derived
{
    public:
        // Default Constructor
        Derived2();
        //! Constructor
        Derived2(int value);

        //! Overload operator < to use Derived2 as a key in a std::set
        bool operator< (const Derived2 &other_derived2) const
        {
            return public_data_ < other_derived2.public_data_; 
        }
}; 

#endif