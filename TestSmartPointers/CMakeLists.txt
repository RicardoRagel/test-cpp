cmake_minimum_required(VERSION 2.8.12)
project(TestSmartPointers)

# Compile against C++ 14 (Smart Pointers)
set(CMAKE_CXX_STANDARD 14)

#########
# BUILD
#########

# Example program
add_executable(test_smart_pointers src/smart_pointers_example.cpp)
add_executable(test_shared_and_weak src/shared_and_weak_example.cpp)