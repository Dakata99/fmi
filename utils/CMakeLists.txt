# Dakata99

add_subdirectory(Doctest)

add_library(Utils STATIC Utils.cpp)
target_include_directories(Utils PRIVATE "${PROJECT_SOURCE_DIR}/STL/Containers/Container adaptors/PQueue/inc")
