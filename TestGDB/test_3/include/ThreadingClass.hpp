#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex
#include <memory>   // smart pointers

using namespace std;

class ThreadingClass
{
    public:
        ThreadingClass();
        ~ThreadingClass();

        // Let's do thing inside this class
        void loop();

        // Callback to be used by the thread
        void threadCallback();

        // Some paramters
        static const int MAX_ITERS = 5;
        static const int LOOP_SLEEP_SECS = 1;
        static const int THREAD_SLEEP_SECS = 2;

    private:

        // A pointer to a thread handler
        unique_ptr<thread> m_thread_ptr;

        mutex m_mutex;
};