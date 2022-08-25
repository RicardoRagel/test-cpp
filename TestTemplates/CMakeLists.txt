cmake_minimum_required(VERSION 2.8.12)
project(TestTemplates)

# Compile against C++ 14 (For templated variables)
set(CMAKE_CXX_STANDARD 14)

#########
# BUILD
#########

# Example programs
add_executable(test_templates src/templates_example.cpp)
add_executable(test_variable_templates src/variable_templates_example.cpp)