cmake_minimum_required(VERSION 2.8.9)
project(TestFunctor)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_functor                 src/example_functor.cpp)
add_executable(test_std_functors            src/example_std_functors.cpp)
add_executable(test_std_functors_with_stl   src/example_std_functors_with_stl.cpp)