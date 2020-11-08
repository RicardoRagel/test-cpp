cmake_minimum_required(VERSION 2.8.9)
project(TestCpp)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########
include_directories(include)
add_executable(test_cpp src/main.cpp src/TestCpp.cpp)
