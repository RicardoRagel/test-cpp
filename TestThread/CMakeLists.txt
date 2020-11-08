cmake_minimum_required(VERSION 2.8.9)
project(TestThread)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

# Finc Threads module
find_package (Threads)

#########
# BUILD
#########

# Threads and Mutex example
add_executable(test_threads_and_mutex src/threads_and_mutex_example.cpp)
target_link_libraries (test_threads_and_mutex Threads::Threads)