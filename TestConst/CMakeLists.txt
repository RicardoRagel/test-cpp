cmake_minimum_required(VERSION 2.8.12)
project(TestConst)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example program
add_executable(test_const src/const_example.cpp)