cmake_minimum_required(VERSION 2.8.12)
project(TestReferences)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example programs
add_executable(test_references src/references_example.cpp)