cmake_minimum_required(VERSION 2.8.12)
project(TestInheritance)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example program
add_executable(test_inheritance         src/inheritance_example.cpp)
add_executable(test_multi_inheritance   src/multiinheritance_example.cpp)
add_executable(test_inheritance_checker src/inheritance_checker.cpp)