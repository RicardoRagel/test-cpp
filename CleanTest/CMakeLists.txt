cmake_minimum_required(VERSION 2.8.9)
project(CleanTest)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_clean src/clean_test.cpp)