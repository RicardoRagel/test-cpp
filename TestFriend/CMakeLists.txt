cmake_minimum_required(VERSION 2.8.12)
project(TestFriend)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

#########
# BUILD
#########

# Example program
add_executable(test_friend src/friend_example.cpp)