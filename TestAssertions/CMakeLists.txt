cmake_minimum_required(VERSION 2.8.9)
project(TestAssertions)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_assertions src/assertions_test.cpp)
add_executable(test_static_assertions src/static_assertions_test.cpp)