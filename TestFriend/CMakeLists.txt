cmake_minimum_required(VERSION 2.8.12)
project(TestFriend)

# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

#########
# BUILD
#########

# Example program
add_executable(test_friend src/friend_example.cpp)