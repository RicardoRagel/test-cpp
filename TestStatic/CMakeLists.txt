cmake_minimum_required(VERSION 2.8.12)
project(TestStatic)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example program
add_executable(test_static src/static_example.cpp)