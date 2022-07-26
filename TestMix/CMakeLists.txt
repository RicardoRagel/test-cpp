cmake_minimum_required(VERSION 2.8.12)
project(RandomTests)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test src/random_tests.cpp)