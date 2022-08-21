cmake_minimum_required(VERSION 2.8.9)
project(TestGDB1)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

# Set debugging flag so the executable contains the necessary symbols
# for debugging
set(CMAKE_BUILD_TYPE Debug)

#########
# BUILD
#########

# Example programs
add_executable(test_gdb_1 src/test_gdb_1.cpp)