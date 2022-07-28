cmake_minimum_required(VERSION 2.8.9)
project(TestQt5Example2)

# Compile against C++ 11
set(CMAKE_CXX_STANDARD 11)

# Workaround so that the MACROS as Q_OBJECT in the header file are compiled
set(CMAKE_AUTOMOC ON) 

# Add Qt
find_package(Qt5 REQUIRED COMPONENTS
    Core
    Widgets
)

message("-- Loading Qt5 Core Headers from: " ${Qt5Core_INCLUDE_DIRS})
message("-- Loading Qt5 Widgets Headers from: " ${Qt5Widgets_INCLUDE_DIRS})
include_directories(
    include
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
)

#########
# BUILD
#########

# Example program. The header files using Q_OBJECT or similar Q Macros must be also added
set(SOURCES 
        src/test_qt5.cpp
        src/mainwindow.cpp
        include/mainwindow.h)

add_executable(test_qt5_ex_2 ${SOURCES})
target_link_libraries(test_qt5_ex_2 Qt5::Core Qt5::Widgets)