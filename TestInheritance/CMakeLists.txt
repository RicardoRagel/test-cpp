cmake_minimum_required(VERSION 2.8.12)
project(TestInheritance)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example program
add_executable(test_inheritance         src/inheritance_example.cpp)
add_executable(test_inheritance_2       src/inheritance_example_2.cpp)
add_executable(test_multi_inheritance   src/multiinheritance_example.cpp)
add_executable(test_inheritance_checker src/inheritance_checker.cpp)