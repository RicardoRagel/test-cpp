cmake_minimum_required(VERSION 2.8.12)
project(TestSmartPointers)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example program
add_executable(test_smart_pointers src/smart_pointers_example.cpp)