cmake_minimum_required(VERSION 2.8.12)
project(TestVolatile)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

# Compile with optimizations
set(CMAKE_BUILD_TYPE Release)

# Find Threads module
find_package (Threads)

#########
# BUILD
#########

include_directories(include)

# Threads and Mutex example
add_executable(test_volatile src/volatile_example.cpp)
target_link_libraries (test_volatile Threads::Threads)