cmake_minimum_required(VERSION 2.8.9)
project(TestQt5Example1)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

# Add Qt
find_package(Qt5 REQUIRED COMPONENTS
    Core
    Widgets
)

message("-- Loading Qt5 Core Headers from: " ${Qt5Core_INCLUDE_DIRS})
message("-- Loading Qt5 Widgets Headers from: " ${Qt5Widgets_INCLUDE_DIRS})
include_directories(
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)

#########
# BUILD
#########

# Example programs
add_executable(test_qt5_ex_1 src/test_qt5.cpp)
target_link_libraries(test_qt5_ex_1 Qt5::Core Qt5::Widgets)