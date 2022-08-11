/*

Testing the difference between shared and weak smart pointers

*/

#include <iostream> // std::cout
#include <memory>   // smart pointers (unique_ptr, ...)

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test SmartPointers:" << endl;
    cout << "--------------------------" << endl << endl;

    cout << "-- Creating the first SHARED pointer: " << endl;
    shared_ptr<double> sh_ptr_1 ( new double (101.001) );
    cout << "Number of pointer to same reference: " << sh_ptr_1.use_count() << endl << endl;
    
    // A new scope
    {
        cout << "-- Creating the second SHARED pointer: " << endl;
        shared_ptr<double> sh_ptr_2 = sh_ptr_1;
        cout << "Number of pointer to same reference: " << sh_ptr_1.use_count() << endl << endl;    
        cout << "Number of pointer to same reference: " << sh_ptr_2.use_count() << endl << endl;

        cout << "-- Creating a WEAK pointer: " << endl;
        weak_ptr<double> wk_ptr = sh_ptr_1;
        cout << "Number of pointer to same reference: " << sh_ptr_1.use_count() << endl << endl; 
        cout << "The WEAK pointer has not increased the counter!!" << endl << endl;
    }

    // Outside the new scope
    cout << "Number of pointer to same reference (outside the second and third pointers scope): " << sh_ptr_1.use_count() << endl; 

    return 0;
}