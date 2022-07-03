cmake_minimum_required(VERSION 2.8.9)
project(TestOperands)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example programs
add_executable(test_operands src/operands_example.cpp)