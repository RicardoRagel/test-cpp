cmake_minimum_required(VERSION 2.8.9)
project(TestVirtual)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example programs
add_executable(test_virtual src/virtual_example.cpp)
add_executable(test_pure_virtual src/pure_virtual_example.cpp)