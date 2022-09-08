/*

Testing the C++ std::async, a method to run a function asynchronously in another
thread directly.

template <class Fn, class... Args>
future<typename result_of<Fn(Args...)>::type> async (launch policy, Fn&& fn, Args&&... args);

std::async returns a std::future<T>, that stores the value returned by function object executed 
by std::async(). Arguments expected by function can be passed to std::async() as arguments 
after the function pointer argument.

*/

#include <iostream> // std::cout
#include <chrono>   // std::chrono
#include <thread>   // std::thread
#include <future>   // std::future
#include <mutex>    

// Aliases
using namespace std;

// Mutex used only for the cout actually 
std::mutex mtx;

// Lazy checking for a random number higher than the received arg
int getRandomNumHigherThan(int min_num)
{
    int result = min_num - 1; //make sure it is lower than arg

    srand(time(NULL)); // Sets random seed

    while(result <= min_num)
    {
        result = rand();

        mtx.lock();
        cout << "(Thread) Random number:\t" << result << endl;
        mtx.unlock();

        this_thread::sleep_for(chrono::seconds(1));
    };

    return result;
} 

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Test Async:" << endl;
    cout << "------------------" << endl;
    cout << "" << endl;

    int min_number = RAND_MAX * 0.75;
    
    cout << "(main) Ordering to get random number higher than " << min_number << endl;

    std::future<int> async_result = std::async(getRandomNumHigherThan, min_number);

    for(int i = 1; i<=3; i++)
    {
        mtx.lock();
        cout << "(main) Meanwhile, I am doing thing " << i << endl;
        mtx.unlock();

        this_thread::sleep_for(chrono::seconds(1));
    }

    mtx.lock();
    cout << "(main) Waiting for the result... " << endl;
    mtx.unlock();

    int result = async_result.get();

    cout << "The result is: " << result << endl;

    cout << "" << endl;

    return 0;
}