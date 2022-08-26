cmake_minimum_required(VERSION 2.8.9)
project(TestLambda)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example programs
add_executable(test_lambda_1 src/lambda_example_1.cpp)
add_executable(test_lambda_2 src/lambda_example_2.cpp)