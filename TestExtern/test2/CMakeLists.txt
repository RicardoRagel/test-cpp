cmake_minimum_required(VERSION 2.8.9)
project(test2)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

include_directories(include)

# Example programs
add_executable(test_extern_in_header src/main.cpp src/module.cpp)