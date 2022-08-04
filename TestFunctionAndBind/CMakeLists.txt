cmake_minimum_required(VERSION 2.8.9)
project(TestFunctionAndBind)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_function_and_bind src/function_and_bind_test.cpp)
add_executable(test_function_and_bind_in_a_class src/function_and_bind_in_a_class_test.cpp)