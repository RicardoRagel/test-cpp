#include <ThreadingClass.hpp>

using namespace std;

ThreadingClass::ThreadingClass()
{
    cout << "Creating a thread..." << endl;

    // Let's create our thread, from inside to outside:
    // * Init a thread setting the callback as a funcion od this class. Every member function receives always a parameter at least: the pointer to the object.
    // * Allocate memory for this thread and returns the reference to it, where this class pointer will point to
    m_thread_ptr = make_unique<thread>(thread(&ThreadingClass::threadCallback, this));
}

ThreadingClass::~ThreadingClass()
{
    cout << "Destructor..." << endl;
    if(m_thread_ptr != NULL)
    {
        cout << "Waiting for joining the thread..." << endl;
        if(m_thread_ptr->joinable())
        {
            m_thread_ptr->join();
            cout << "joined!" << endl;
        }
    }
}

void ThreadingClass::loop()
{
    int index = 0;
    int sleep_duration = LOOP_SLEEP_SECS;
    while(index < MAX_ITERS)
    {
        // Using the mutex to avoid the console output are mixed
        m_mutex.lock();
        cout << "In the loop... " << index << endl;
        m_mutex.unlock();

        this_thread::sleep_for(chrono::seconds(sleep_duration));
        index++;
    }
}

void ThreadingClass::threadCallback()
{
    int index = 0;
    int sleep_duration = THREAD_SLEEP_SECS;
    while(index < MAX_ITERS)
    {
        // Using the mutex to avoid the console output are mixed
        m_mutex.lock();
        cout << "In the thread... " << index << endl;
        m_mutex.unlock();

        this_thread::sleep_for(chrono::seconds(sleep_duration));
        index++;
    }
}