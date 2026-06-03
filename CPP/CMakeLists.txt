# Dakata99

cmake_minimum_required(VERSION 3.22)
project(CPP C CXX)

# Set the global C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(GLOBAL PROPERTY CXX_STANDARD 20)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

# include(cmake/formatter.cmake)
# include(cmake/linter.cmake)

add_subdirectory(OOP)
add_subdirectory(STL)
add_subdirectory(Utils)
