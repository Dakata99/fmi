# Dakata99

# Add PQueue as a static library
add_library(pqueue STATIC src/PQueue.cpp)
target_include_directories(pqueue PUBLIC inc src)

# Add test
add_executable(pqueue_unittest test/test.cpp)
target_link_libraries(pqueue_unittest pqueue Utils)
target_include_directories(pqueue_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(pqueue_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
