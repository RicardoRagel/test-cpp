/*! \mainpage Cpp Tests Package
 *
 * \section intro_sec A Compilation of different Cpp examples
 *
 * This package contains several examples grouped in a switch. 
 * Run the executable following of a number to check each one.
 * 
 * The classes TestCpp, Derived and Derived used in these examples
 * have been documented in this API.
 */
#include "TestCpp.hpp"

#include <iostream>
#include <bitset>
#include <math.h>
#include <string.h>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>

#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "Test CPP:" << endl;
    cout << "---------" << endl;

    // Selected Test
    int run_test;
    if(argc < 2)
    {
        run_test = 1;
    }
    else
    {
        //cout << "Introduced value contains " << strlen(argv[1]) << " digits" << endl;
        run_test = atoi(argv[1]); // int = atoi(char *)
    }

    cout << "Running Test " << run_test << endl << endl;

    switch(run_test)
    {
        /*
            Test 1: calling different constructor of the base class
        */
        case 1:
        {
            cout << "-- Calling Non-default constructor: " << endl;
            TestCpp test_cpp_1(33);

            cout << "-- Calling default constructor: " << endl;
            TestCpp test_cpp_2;

            cout << "-- Calling copy constructor, that has not be defined (so it doesn't print anything): " << endl;
            TestCpp test_cpp_3 = test_cpp_1;

            cout << "-- However, it has copied the data: " << test_cpp_3.getPrivateData() << endl;
            
            break;
        }
        /*
            Test 2: calling to the default constructor of the derived class.
            
            Derived class constructor will call first base class constructor due to the
            derived class constructor doesn't define which base constructor call.
        */
        case 2:
        {
            Derived derived;

            break;
        }
        /*
            Test 3: Allocating memory
        */
        case 3:
        {
            Derived *derived_ptr = new Derived[10];
            delete derived_ptr;

            break;
        }
              
        /*
            Test 4: Smart IoT Labs: ++i VS i++
        */
        case 4:
        {
           int i = 1;
           printf("%d\n",i);    // 1
           printf("%d\n",i++);  // var ++, first return the current var value and later increment it. 1
           printf("%d\n",++i);  // ++ var, first increase the var and later return the value. 3
           printf("%d\n",i);    // 3
           printf("%d, %d\n", ++i, i++); 
           // In this last case, it depends of the compiler but it could first (++i) increment i value 
           // and return the result, later (++i) increment it again but return previous i value, so the result could be 5, 3
           
           // No worries, in these cases are the same
           for(int j=0; j<10; j++)
                cout << j;
           cout << endl;
           for(int j=0; j<10; ++j)
                cout << j;
           cout << endl;

           break;
        }

        /*
            Test 5: Working with bits
        */
        case 5:
        {
           uint8_t i = 14;
           std::bitset<8> bits_i(i);    // 1 byte memory
           cout << bits_i << endl;

           uint8_t i2 = i<<2;   // Moving bits to the left
           std::bitset<8> bits_i2(i2);
           cout << bits_i2 << endl;

           uint8_t i3 = i & i2; // Binary AND. Don't confuse with the Logical AND (&&), that returns 00000001 (true) or 00000000 (false)
           std::bitset<8> bits_i3(i3);
           cout << bits_i3 << endl;

           uint8_t j = ~i; // complementary
           std::bitset<8> bits_j(j);
           cout << bits_j << endl;

           uint8_t k = !i; // logical negation, so it will return true or false
           std::bitset<8> bits_k(k);
           cout << bits_k << endl;

           // Getting the MSB and LSB
           uint16_t max2bytes = pow(2,16) - 1;
           cout << "2 bytes max number: " <<  max2bytes << endl;
           std::bitset<2*8> bits_max2bytes(max2bytes);
           cout << "In binary: " << bits_max2bytes << endl;
           
           uint8_t msb = max2bytes >> 8;
           std::bitset<8> bits_msb(msb);
           cout << "The MSB: " << bits_msb << endl;
           
           uint16_t temp = max2bytes << 8;
           uint8_t lsb = temp >> 8;
           std::bitset<8> bits_lsb(lsb);
           cout << "The LSB: " << bits_lsb << endl;

           // The old way to print bits: apply a one-bit-to-1 mask and moving the bit to the lsb
           int n = 14;
           for(int k=7; k>=0; k--)
           {
               printf("%d", (n & ( 1 << k )) >> k);
           }
           cout << endl;

           break;
        }
        
        /*
            Test 6: Standard containers: Sequence and Fixed-size Arrays. STD::ARRAY (c++11)
        */
        case 6:
        {

            std::array<Derived, 10> my_array = {Derived(0), Derived(1), Derived(2)};
            my_array[0].public_data_ = 33;
            my_array.at(9).public_data_ = 99;
            cout << "My array size: " << my_array.size() << endl;
            for (auto it = my_array.begin(); it<my_array.end(); it++)
                cout << it->public_data_ << endl;
            /*
                // std::aray has not modifier functions that change the size
                my_array.clear();                   // fails             
                Derived new_derived;                // fails
                my_array.push_back(new_derived);    // fails
            */

            break;
        }
        
        /*
            Test 7: Standard containers. Sequence and Dynamic-size Arrays with Random Access. STD::VETOR and STD::DEQUE
        */
        case 7:
        {
            // Ended Queue -> Vector
            // Save data sequencially AND CONTIGUOUSLY (so you could use a pointer instead of an iterator)
            cout << "STD::VECTOR" << endl;
            cout << "-----------" << endl;
            std::vector<Derived> my_vector = {Derived(0), Derived(1), Derived(2)};
            my_vector.pop_back();
            my_vector.push_back(Derived(22));
            
            cout << "My Vector using an iterator:" << endl;
            for (auto it = my_vector.begin(); it<my_vector.end(); it++)
                cout << it->public_data_ << endl;
            
            cout << "My Vector using a range-based for instead of an iterator: " << endl;
            //for(Derived element : my_vector)
            for(const auto& element : my_vector) // Note: it is possible to use auto or auto& if you need to modify a value
            {
                cout << element.public_data_ << endl;
            }

            cout << "My Vector using an inverse iterator:" << endl;
            for (auto it = my_vector.rbegin(); it<my_vector.rend(); it++)
                cout << it->public_data_ << endl;

            cout << "My new vector erasing the element with value 1: " << endl;
            for (auto it = my_vector.begin(); it<my_vector.end(); it++)
            {
                if(it->public_data_ == 1)
                {
                    it = my_vector.erase(it); // return the pointer to the next element of the ereased one
                    it--; // decrease one to get it in the following iteration
                }
                else
                {
                    cout << it->public_data_ << endl;
                }
            }
            cout << endl;

            my_vector.push_back(33);
            cout << "My new vector inserting a new element 11 before the value 22: " << endl;
            auto it_last_element = my_vector.end();
            for (auto it = my_vector.begin(); it<it_last_element; it++)
            {
                if(it->public_data_ == 22)
                {
                    it = my_vector.insert(it, 11); // return an iterator to this new element
                    cout << it->public_data_ << endl;
                    it++; // jump one to the next one, that will be 22, so the next iteration will be the next one (33)
                    cout << it->public_data_ << endl;
                    it_last_element = my_vector.end(); // update the loop final condition with the new end element iterator
                }
                else
                {
                    cout << it->public_data_ << endl;
                }
            }
            cout << endl;

            // Double-Ended Queue -> Deque
            // Allow add elements also at the front of the container
            cout << "STD::DEQUE" << endl;
            cout << "----------" << endl;
            std::deque<Derived> my_deque = {Derived(0), Derived(1), Derived(2)};
            my_deque.pop_back();
            my_deque.push_back(Derived(22));
            my_deque.pop_front();
            my_deque.push_front(Derived(-1));
            cout << endl << "My DeQue:" << endl;
            for (auto it = my_deque.begin(); it<my_deque.end(); it++)
                cout << it->public_data_ << endl;
            cout << endl;

            break;
        }
        
        /*
            Test 8: Standard containers. Sequence and Dynamic-size Arrays with NO Random Access. STD::FORWARD_LIST and STD::LIST
        */
        case 8:
        {
            // Linked List -> Forward_List.
            // Implemented as singly-linked lists. They can store each of the elements they contain in different and UNRELATED storage locations. The ordering is kept by the association to each element of a link to the next element in the sequence. 
            // Use in case of small series of large objects, where vector find it difficult to allocate memory.
            // Are also good in insertion, removal and moving operations. If you use a vector, you have to iterate. With FList you can acces using the pointer to the next element
            // Inconvenient: Not random access, that is neither .at(), nor [] operator. You have to use the only element acces .front() and the pointers or iterators.
            //               Increase allocated memory size.
            cout << "STD::FORWARD_LIST" << endl;
            cout << "-----------------" << endl;
            std::forward_list<Derived> my_flist = {Derived(0), Derived(1), Derived(2)};
            my_flist.push_front(Derived(3));    // We have only access to the front of the list, neither to the back() nor to random access
            cout << endl << "My FList after add one more element at the front:" << endl;
            for (auto it = my_flist.begin(); it!=my_flist.end(); it++)                      // NOTICE THAT we can't use it<my_flist.end() because it are not contiguously
                cout << it->public_data_ << endl;
            
            cout << endl << "My FList after call to the sort() function:" << endl;
            //my_flist.sort(); 
            // Sort needs a comparator if the templated class is not basic variable
            struct DerivedComparator
            {
                // Compare 2 Derived objects using the internal data
                bool operator ()(const Derived & d1, const Derived & d2)
                {
                    return d1.public_data_ < d2.public_data_;
                }
            };
            my_flist.sort(DerivedComparator());
            for (auto element : my_flist)
                cout << element.public_data_ << endl;

            cout << endl << "Adding two forward list:" << endl;
            std::forward_list<Derived> second_flist = {Derived(4), Derived(5)};
            std::forward_list<Derived> third_flist(second_flist);
            third_flist.insert_after(third_flist.before_begin(), my_flist.begin(),my_flist.end());  // or better:
            //third_flist.splice_after(third_flist.before_begin(), my_flist); // but splice_after will clear my_flist
            for (auto element : third_flist)
                cout << element.public_data_ << endl;

            cout << endl << "Merguing two forward list:" << endl;
            std::forward_list<Derived> serie1 = {Derived(100), Derived(20)};
            std::forward_list<Derived> serie2 = {Derived(45), Derived(10)};
            serie1.sort(DerivedComparator());
            serie2.sort(DerivedComparator());
            serie1.merge(serie2, DerivedComparator());
            for (auto element : serie1)
                cout << element.public_data_ << endl;

            // Double Linked List -> List.
            // std::list is a container that supports constant time insertion and removal of elements from anywhere in the container. 
            // Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient.
            // Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references. An iterator is invalidated only when the corresponding element is deleted.
            cout << endl;
            cout << "STD::LIST" << endl;
            cout << "-----------------" << endl;
            std::list<int> my_list = {0, 1, 2};
            my_list.push_front(-1);
            my_list.push_back(-1);
            cout << "My List after add one more element at the front and at the end:" << endl;
            for(int element : my_list)
                cout << element << endl;

            cout << endl << "My List after removing duplicated elements:" << endl;
            my_list.sort();
            my_list.unique(); // remove consecutive (so, first you have to sort it) elements with the same value
            for(int element : my_list)
                cout << element << endl;

            break;
        }

        /*
            Test 9: Standard containers. Associative and Sorted containers of unique Keys: STD::SET<Key> ; STD::SET<Key,Comparator>
        */
        case 9:
        {
            // List of unique elemtents of type Key, sorted by Key using a Comparator -> std::set<Key,Comparator> 
            cout << "STD::SET" << endl;
            cout << "--------" << endl;
            
            // Set of ints
            std::set<int> my_ints_set = {2, 3, 1, 3};
            //std::set<int, std::less<int>> my_ints_set = {2, 3, 1, 3}; // Default comparator
            //std::set<int, std::greater<int>> my_ints_set = {2, 3, 1, 3}; // other std defined comparator
            cout << endl << "A set of ints is automatically sorted using the comparator value_a < value_b:" << endl;
            for(int element : my_ints_set)
                cout << element << endl;

            // Set of strings
            std::set<string> my_strings_set;
            my_strings_set.insert("Bannana");
            my_strings_set.insert("Melon");
            my_strings_set.insert("Apple");
            my_strings_set.insert("Apple");
            cout << endl << "A set of strings is automatically sorted in alphabetical order: " << endl;
            for(string element : my_strings_set)
                cout << element << endl;
            
            // Set of non-basic class, you need to overload the operator < for that class or
            // provide a Comparator function to the class:
            // struct DerivedComparator
            // {
            //     bool operator()(const Derived &d1, const Derived &d2)
            //     {
            //         return d1.public_data_ < d2.public_data_; // Use > if you want from higher to lower order
            //     }
            // };
            // std::set<Derived, DerivedComparator> my_set = {Derived(33), Derived(11), Derived(22)};
            // cout << endl << "A set of a non-basic class sorted by a Comparator function" << endl;
            // for(Derived element : my_set)
            //     cout << element.public_data_ << endl;

            // std::set<Derived2> my_set_2 = {Derived2(33), Derived2(11), Derived2(22)};
            // cout << endl << "A set of a non-basic class sorted by his own operator <" << endl;
            // for(Derived element : my_set_2)
            //     cout << element.public_data_ << endl;

            // Using a std::set
            // cout << endl << "Using the set: " << endl;
            // cout << "You can use find(element) to get an iterator to that element" << endl;
            // auto it = my_set.find(Derived(22));
            // while(it != my_set.end())
            // {
            //     cout << it->public_data_ << endl;
            //     it++;
            // }
            // cout << "You can use lower_bound(element2) to get an iterator to closer element to the provided element2" << endl;
            // auto it_to_next = my_set.lower_bound(Derived(12));
            // while(it_to_next != my_set.end())
            // {
            //     cout << it_to_next->public_data_ << endl;
            //     it_to_next++;
            // }
            // // It exists another really similar: 
            // //      lower_bound =  returns an iterator to the first element not less than the given key
            // //      upper_bound =  returns an iterator to the first element greater than the given key

            // // WARNING: Values (Keys) on a std::set are not modifiable. To modify them, you have to remove and insert it
            // cout << "You can NOT modify elements / keys on a std::set, you need to extract or remove it and insert a new one:" << endl;
            // auto it_22 = my_set.find(Derived(22));
            // Derived d = *it_22;
            // cout << "Copied: " << d.public_data_ << endl;
            // my_set.erase(it_22);
            // cout << "Removed: " << endl;
            // for(Derived element : my_set)
            //     cout << element.public_data_ << endl;
            // d.public_data_ = 23;
            // cout << "Modified: " << d.public_data_ << endl;
            // my_set.insert(d);
            // for(Derived element : my_set)
            //     cout << element.public_data_ << endl;
            
            // You can also merge different std::set like for std::list

            break;
        }

        /*
            Test 10: Standard containers. Associative and Sorted containers of Key-value pairs, with unique keys: STD::MAP<Key,Value>, STD::MAP<Key,Value,Comparator>
        */
        case 10:
        {
            // They are really similar to std::std, but in this case, elements contain also a value together the unique key
            cout << "STD::MAP" << endl;
            cout << "--------" << endl;
            std::map<int,string> my_map = { {0, "Sevilla"}, {1, "Madrid"}, {2, "Barcelona"} };
            my_map.insert({-1, "Ceuta"});
            for(auto element : my_map)
                cout << element.first << ": " << element.second << endl;

            // As you can see all of the previous elements are std::pair<Key,Value>
            std::pair<int, string> element; // = {3, "Bilbao"}; 
            element.first = 3; // Key
            element.second = "Bilbao"; // Value
            my_map.insert(element);
            
            // For maps, you can use random access using the key:
            cout << "The value of the id 3 is: " << my_map[3] << endl;
            my_map[3] = "Vitoria";
            cout << "But we can easily change it to: " << my_map[3] << endl;

            // The iterators of std::map are also pointers to std::pairs, the elements
            for(std::map<int,string>::iterator it = my_map.begin(); it != my_map.end(); it++)
                cout << it->first << ": " << it->second << endl;

            break;
        }

        /*
            Test 11: Standard containers. Function std::sort(itBegin, itEnd, Comparator) (c++ 17)
        */
        case 11:
        {
            // The function std::sort allow you to sort any standard container
            cout << "STD::SORT" << endl;
            cout << "--------" << endl;
            
            std::vector<string> my_strings = { "Francisco", "Fran", "Alberto", "Miguel Angel", "Victor Manuel", "Ricardo", 
                                               "Vicente", "Rigoberto", "Zuleida", "Clara", "Koeman", "Kanoute", "Ana"};
            
            cout << endl << "Current unsorted vector: " << endl;
            for(auto element : my_strings)
                cout << element << endl;
            
            cout << endl << "Defaul sort, in alphabetical order: " << endl;
            std::sort(my_strings.begin(), my_strings.end());
            for(auto element : my_strings)
                cout << element << endl;

            cout << endl << "Custom sort, ordered by lenght: " << endl;
            struct LengthComparator
            {
                bool operator() (const string &s1, const string &s2)
                {
                    return strlen(s1.c_str()) < strlen(s2.c_str());
                }
            };
            std::sort(my_strings.begin(), my_strings.end(), LengthComparator());
            for(auto element : my_strings)
                cout << element << endl;
            
            break;
        }

        /*
            Test 12: Standard containers. Functions std::min_element(itBegin, itEnd, Comparator) and std::max_element (c++ 17)
                     
                     Extra: std::distance(it1, it2) return the number of hops from it1 to it2 
        */
        case 12:
        {
            // Simply returns an iterator to the min and max values, and the distance (in hops) from two iterators
            std::vector<int> v = {14, 2, 55, 33, 1800, 42, 100};
            cout << "My vector: " << v[0];
            for(auto it = ++v.begin(); it != v.end(); it++) 
                cout << ", " << *it;
            cout << endl;
            
            auto it_min = std::min_element(v.begin(), v.end());
            auto it_max = std::max_element(v.begin(), v.end());
            cout << "Min: " << *it_min << ", Max: " << *it_max << endl;
            cout << "Distance from Min to Max: " << std::distance(it_min, it_max) << endl;

            break;
        }

        /*
            Test 13: Lambda functions: 
                        * Funciones anónimas que son creadas en tiempo de ejecución y no en tiempo de compilación.
                        * Posee unos corchetes con los parámetros de captura y después, como cualquier otra función, tiene entre paréntesis sus parámetros normales. Además tiene un cuerpo, en el que podemos realizar operaciones.
                        * Si queremos marcarle el tipo de devolución, después de los parámetros, con una flecha podemos marcarle el tipo,
        */
        case 13:
        {
            int b = 1;
            double c = 2.2;
            cout << "b: " << b << endl;
            cout << "c: " << c << endl;
            // Lambda funtion:     
            // auto function_name = [captured_params](input_params)->return_type { // Do stuff here };
            
            // Sin capturar nada
            auto f1 = [](int a) -> double { return a + 2.2;};
            cout << "Calling f1(3), a + 2.2 = "<< f1(3) << endl;
            
            // Capturando una copia de b y c
            auto f2 = [b, c](int a) -> double 
            {
                //c = 3.3; You can not modify a captured parameter as copied
                return a + c;
            };   
            cout << "Calling f2(3), a + c = "<< f2(3) << endl;

            // Capturando una referencia de b y c
            auto f3 = [&b, &c](int a) -> double
            {
                c += 1;
                return a + c;
            };
            cout << "Calling f3(3), c+1 and a + c = " << f3(3) << ". c = " << c << endl;
            
            // Lo tipico es usar directamente [=] or [&] para capturar todo el scope por copia or referencia

            break;
        }


        ///TODO: std::function, make_function, threads, std::copy, std::find, std::for_each, ...

        default:
            cout << "Selected test doesn't exist" << endl;



    }//switch

    return 0;
}