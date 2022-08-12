/*

Example usage of pure virtual method in inheritance.

We create first an Abstract class and multiple derived class from it.

Later we create a function that receives an object of the Abstract class but
to be used with object of the derived classes.
*/

#include <iostream> // std::cout

// Aliases
using namespace std;

enum OBJECT_TYPES {HAT = 1, PENCIL, KEYBOARD};

// Abstract Base Class
class Object
{
    public:
        virtual uint8_t getType() = 0;
};

// Derived Classes
class Hat : virtual public Object // virtual base class inheritance is only to avoid multiple Object inheritance
{
    public:
        uint8_t getType()
        {
            return HAT;
        }
};
class Pencil : virtual public Object
{
    public:
        uint8_t getType()
        {
            return PENCIL;
        }
};
class Keyboard : virtual public Object
{
    public:
        uint8_t getType()
        {
            return KEYBOARD;
        }
};


// Function to check what type is. It receives a reference to an object of the Abstract class,
// is it possible???
// Yes, because actually it will not be an object of the abstract class (we cannot create an object of this),
// it will be an object of an Object derived class
bool isPencil(Object & obj)
{
    if(obj.getType() == PENCIL)
        return true;
    
    return false;
}

// **** MAIN **** //
int main(int argc, char **argv)
{
    Pencil p;
    
    if(isPencil(p))
    {
        cout << "Yeah, it is a pencil" << endl;
    }

    return 0;
}