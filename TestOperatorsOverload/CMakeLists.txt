cmake_minimum_required(VERSION 2.8.9)
project(TestOperatorsOverload)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_operators_overload src/operators_overload_test.cpp)