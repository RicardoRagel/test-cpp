cmake_minimum_required(VERSION 2.8.9)
project(TestConst)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example program
add_executable(test_const src/const_example.cpp)