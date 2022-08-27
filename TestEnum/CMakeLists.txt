cmake_minimum_required(VERSION 2.8.9)
project(TestEnum)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_enum        src/enum_test.cpp)
add_executable(test_class_enum  src/enum_class_test.cpp)