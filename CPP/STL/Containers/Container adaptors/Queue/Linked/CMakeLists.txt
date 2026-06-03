# Dakata99

# Add Queue as a static library
add_library(lqueue STATIC src/Queue.cpp)
target_include_directories(lqueue PUBLIC inc src)

# Add test
add_executable(lqueue_unittest test/test.cpp)
target_link_libraries(lqueue_unittest lqueue)
target_include_directories(lqueue_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest)
target_compile_definitions(lqueue_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
