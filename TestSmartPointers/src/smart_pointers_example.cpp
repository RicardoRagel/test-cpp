/*

Comparing C++ pointers and smart pointers

*/

#include <iostream> // std::cout
#include <unistd.h> // sleep(), usleep()
#include <memory>   // smart pointers (unique_ptr, ...)

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test SmartPointers:" << endl;
    cout << "--------------------------" << endl << endl;
    cout << "Type 1 (C++ pointers), 2 (C++ pointers forgetting to delete them) 3 (SmartPointers: unique_ptr) or 4 (SmartPointers: shared_ptr): ";
    
    int selection;
    cin >> selection;
    cout << endl;

    switch(selection)
    {
        case 1:
        {
            cout << "Testing c++ pointers (deleting them correctly). Check the memory usage using htop in a terminal." << endl;
            while(true)
            {
                cout << endl << "-- New double! --" << endl;
                double* num = new double(); 
                *num = 33.33;
                usleep(1e1);
                delete num;
            }

            break;
        }
        case 2:
        {
            cout << "Testing c++ pointers (NOT deleting them correctly). Check the memory usage using htop in a terminal." << endl;
            while(true)
            {
                cout << endl << "-- New double! --" << endl;
                double* num = new double(); 
                *num = 33.33;
                // usleep(1e1);
            }

            break;
        }
        case 3:
        {
            cout << "Testing Smart Pointers unique_ptr. Check the memory usage using htop in a terminal." << endl;
            while(true)
            {
                cout << endl << "-- New double! --" << endl;
                double num = 33.33;
                unique_ptr<double> sm_ptr_1 = std::make_unique<double>(num);
                // Or directly creating only the pointer: 
                // unique_ptr<double> sm_ptr_1 = std::make_unique<double>(double(44.44));
                //unique_ptr<double> sm_ptr_1( new double(44.44) );
                
                if(sm_ptr_1)
                    cout << "Content of first unique_ptr: " << *sm_ptr_1 << endl;
                
                unique_ptr<double> sm_ptr_2 = std::move(sm_ptr_1);
                cout << "Content of second unique_ptr after move(): " << *sm_ptr_2 << endl;
                
                // Segmentation fault (core dumped):
                // cout << "Content of first unique_ptr: " << *sm_ptr_1 << endl;
                if(!sm_ptr_1)
                    cout << "First unique pointer NULL" << endl;

                usleep(1e5);
            }

            break;
        }
        case 4:
        {
            cout << "Testing Smart Pointers shared_ptr. Check the memory usage using htop in a terminal." << endl;
            while(true)
            {
                cout << endl << "-- New double! --" << endl << endl;
                double num = 33.33;
                shared_ptr<double> sm_ptr_1 = std::make_shared<double>(num);
                
                cout << "Content of first unique_ptr: " << *sm_ptr_1 << endl;
                cout << "Number of pointer to same reference: " << sm_ptr_1.use_count() << endl << endl;
                
                shared_ptr<double> sm_ptr_2 = sm_ptr_1;
                cout << "Content of second unique_ptr after equal to the first one: " << *sm_ptr_2 << endl;
                cout << "Content of first unique_ptr after creating the second one: " << *sm_ptr_1 << endl << endl;
                
                cout << "Number of pointer to same reference: " << sm_ptr_2.use_count() << endl << endl;

                sm_ptr_1.reset();
                cout << "Number of pointer to same reference after reset/delete the first one: " << sm_ptr_2.use_count() << endl << endl;

                usleep(1e5);
            }

            break;
        }
        default:
            printf("Non valid option...\n");
    }

    return 0;
}