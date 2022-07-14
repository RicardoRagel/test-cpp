cmake_minimum_required(VERSION 2.8.12)
project(TestCpp)

#########
# SETUP
#########
# Compile against C++ 17
set(CMAKE_CXX_STANDARD 17)

# Documentation
option(BUILD_DOC "Build doxygen documentation" OFF)
if(BUILD_DOC)
find_package(Doxygen)
if(DOXYGEN_FOUND)
        message(STATUS "Build documentation activated")
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        add_custom_target( docs_doxygen ALL
                           COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                           WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                           COMMENT "Generating API documentation with Doxygen"
                           VERBATIM )
    else (DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen need to be installed to generate the doxygen documentation")
    endif()
else(BUILD_DOC)
    message(STATUS "Build documentation deactivated")
endif(BUILD_DOC)

#########
# BUILD
#########
include_directories(include)
add_executable(test_cpp src/main.cpp src/TestCpp.cpp)
