cmake_minimum_required(VERSION 3.21)

# Project name and version
project(zadanie3)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES src/*.cpp)

# Add the executable
add_executable(zadanie3 main.cpp ${SOURCES})
