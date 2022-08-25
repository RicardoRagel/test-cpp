cmake_minimum_required(VERSION 2.8.12)
project(TestStatic)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

include_directories(include/)

# Example program
add_executable(test_static_scope_features src/main.cpp src/Class.cpp)