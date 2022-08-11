cmake_minimum_required(VERSION 2.8.9)
project(TestVirtualBaseClass)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_virtual_base_class src/virtual_base_class_example.cpp)