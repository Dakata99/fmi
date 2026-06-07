# Dakata99

# Add base Graph as a static library
add_library(basegraph STATIC Graph.cpp)
target_include_directories(basegraph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
