cmake_minimum_required(VERSION 2.8.9)
project(TestStdAsync)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

find_package(Threads)

#########
# BUILD
#########

# Example programs
add_executable(test_async src/async_test.cpp)
target_link_libraries (test_async Threads::Threads)