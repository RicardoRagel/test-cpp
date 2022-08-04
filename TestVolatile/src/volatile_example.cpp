/*

Testing the Keyword volatile.

When using a variable that doesn't change inside a scope, the compiler can assume that it can be optimised replacing it by its value.

However, it could change from outside, for example from another thread using a pointer to this variable (using a reference the most of 
compilers will not optimise it and will look at the variable again).

Check the behaviour of this program when using the variable global_limit as non-volatile and volatile. In case of non-volatile,
the reader thread will not be aware that the writer thread has changed it, and will iterate more than the expected. It is solved setting the
volatile keyword. 

*/

#include <iostream> // std::cout
#include <thread>   // std::thread

// Aliases
using namespace std;

//const int global_limit = 10;
volatile const int global_limit = 10;

void reader()
{
    cout << "(reader) Init" << endl;

    cout << "(reader) Start iterating from 0 to global_limit (10)" << endl;

    for(int i=0; i<global_limit; i++)
    {
        cout << "(reader) i: " << i << endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    cout << "(reader) Finishes" << endl;
}

void writer()
{
    cout << "(writer) Init" << endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(2));

    cout << "(writer) Decreasing global_limit from 10 to 4" << endl;

    int * ptr_limit = (int *) &global_limit;
    *ptr_limit = 4;

    cout << "(writer) Finishes" << endl;
}

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Threads:" << endl;
    cout << "--------------------" << endl;

    // Spawn two new threads
    std::cout << "(main) reader and writer will be executed concurrently...\n";
    std::thread reader_th (reader);
    std::thread writer_th (writer);

    // Synchronize threads
    reader_th.join();   // pauses until reader finishes
    writer_th.join();   // pauses until writer finishes

    std::cout << "(main) reader and writer completed.\n";

    return 0;
}