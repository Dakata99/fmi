# Dakata99

file(GLOB SOURCES src/*)
message(STATUS "SOURCES = ${SOURCES}")

add_library(TreeAlgorithms STATIC ${SOURCES})
target_include_directories(TreeAlgorithms PRIVATE ${PROJECT_SOURCE_DIR}/STL/Containers/Other/Graph/Trees)
