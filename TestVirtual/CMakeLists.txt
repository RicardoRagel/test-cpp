cmake_minimum_required(VERSION 2.8.12)
project(TestVirtual)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_virtual src/virtual_example.cpp)
add_executable(test_pure_virtual src/pure_virtual_example.cpp)
add_executable(test_pure_virtual_usage_example src/pure_virtual_usage_example.cpp)