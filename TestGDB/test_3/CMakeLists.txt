cmake_minimum_required(VERSION 2.8.12)
project(TestGDB3)

# Compile against C++ 14 (Smart Pointers)
set(CMAKE_CXX_STANDARD 14)

# Set debugging flag so the executable contains the necessary symbols
# for debugging
set(CMAKE_BUILD_TYPE Debug)

# Find Threads module
find_package (Threads)

#########
# BUILD
#########

include_directories(include)

# Threading Class example
add_executable(test_gdb_3 src/threading_class_example.cpp src/ThreadingClass.cpp)
target_link_libraries (test_gdb_3 Threads::Threads)
