cmake_minimum_required(VERSION 2.8.12)
project(TestThreads)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

# Find Threads module
find_package (Threads)

#########
# BUILD
#########

include_directories(include)

# Threads and Mutex example
add_executable(test_threads_and_mutex src/threads_and_mutex_example.cpp)
target_link_libraries (test_threads_and_mutex Threads::Threads)

# Threading Class example
add_executable(test_threading_class src/threading_class_example.cpp src/ThreadingClass.cpp)
target_link_libraries (test_threading_class Threads::Threads)
