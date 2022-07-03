cmake_minimum_required(VERSION 2.8.9)
project(TestTemplates)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example programs
add_executable(test_templates src/templates_example.cpp)