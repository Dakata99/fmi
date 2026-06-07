# Dakata99

cmake_minimum_required(VERSION 3.22)
project(FMI C CXX)

# Set the global C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add subjects
add_subdirectory(discrete-math/notes)
add_subdirectory(oop)
add_subdirectory(stl)
add_subdirectory(utils)
