/*

Testing the C++ templates

*/

#include <iostream> // std::cout
#include <string>
#include <vector>

// Aliases
using namespace std;

template <class T>
void fun_1(int arg)
{
    cout << arg << endl;
    cout << (T)arg << endl;
}

template <class T>
T fun_2(T x, T y)
{
    return x>y? x : y;
}

template <>
//bool fun_2(bool x, bool y)
bool fun_2<bool>(bool x, bool y)
{
    cout << "This is a specialization of fun_2" << endl;
    return true;
}

template <class T, class U>
bool fun_3(T x, U y)
{
    return x>y? true : false;
}

template <class T>
class A
{
    std::vector<T> buff;
    
    public:
        void add(T x)
        {
            buff.push_back(x);
        }

        void print1()
        {
            for(auto elem : buff)
            {
                cout << elem << endl;
            }
        }
        
        void print2()
        {
            // Note: iterator dependents on the std::vector data type, so it is necessary to specify that it is a typename
            for(typename std::vector<T>::iterator it = buff.begin(); it != buff.end(); it++ )
            {
                cout << *it << endl;
            }
        }

        // Same that print2, but let's define it outside
        void print3();
};

template <class T>
void A<T>::print3()
{
    // Note: iterator dependents on the std::vector data type, so it is necessary to specify that it is a typename
    for(typename std::vector<T>::iterator it = buff.begin(); it != buff.end(); it++ )
    {
        cout << *it << endl;
    }
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Templates:" << endl;
    cout << "---------------------" << endl;

    cout << "- Testing simple template 1:" << endl;
    fun_1<int>(3);
    fun_1<char>('3'); 
    
    cout << "- Testing simple template 2:" << endl;
    cout << fun_2<int>(2,7) << endl;
    cout << fun_2<char>('a','z') << endl;
    cout << fun_2<char*>("abcde","abcdefg") << endl;
    cout << fun_2<string>("abcde","abcdefg") << endl;
    cout << fun_2(true,true) << endl;
    
    // It's possible to call without the template only in case all the passed args are of the same type
    //cout << fun_2(2,7) << endl;       //OK
    //cout << fun_2(2,'a') << endl;     //MAKE ERROR
    
    cout << "- Testing simple template 3:" << endl;
    cout << fun_3<int, int>(2,7) << endl;
    cout << fun_3<char, int>('a',7) << endl;

    cout << "- Testing class template 1:" << endl;
    A<int> a;
    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.print1();
    a.print2();
}