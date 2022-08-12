cmake_minimum_required(VERSION 2.8.9)
project(TestCastOperators)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_dynamic_cast        src/dynamic_cast_example.cpp)
add_executable(test_static_cast         src/static_cast_example.cpp)
add_executable(test_reinterpret_cast    src/reinterpret_cast_example.cpp)
add_executable(test_const_cast          src/const_cast_example.cpp)