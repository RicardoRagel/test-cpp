cmake_minimum_required(VERSION 2.8.9)
project(test1)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_extern src/file_2.cpp src/file_1.cpp)