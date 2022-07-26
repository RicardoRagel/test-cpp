cmake_minimum_required(VERSION 2.8.12)
project(TestExceptions)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_exceptions src/exceptions_example.cpp)