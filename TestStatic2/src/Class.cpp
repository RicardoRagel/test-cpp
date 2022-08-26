#include "Class.hpp"
#include <iostream> // std::cout

// Some functions to test STATIC FUNCTIONS
void non_static_print()
{
    std::cout << " -- Aloha, I am the NON static print -- " << std::endl;
};

static void static_print()
{
    std::cout << " -- Aloha, I am the static print -- " << std::endl;
};

// Defining Class
Class::Class()
{

}

int Class::variable = 33;

int Class::getStaticVariable()
{
    return variable;
}

// Note that static is only set in the declaration, not in the definition for the class
void Class::callStaticPrint()
{
    static_print();
}

// We define it here, but it will be used in the main.cpp
int extern_global_var = 33;

// UNNAMED NAMESPACE: avoid any other source file access to it
namespace
{
    int unnamed_global_var = 1234;
}

// Let's also add this to be accessible with extern
int named_global_var = 5678;
