# Dakata99

# Add Queue as a static library
add_library(cqueue STATIC src/Queue.cpp)
target_include_directories(cqueue PUBLIC inc src)

# Add test
add_executable(cqueue_unittest test/test.cpp)
target_link_libraries(cqueue_unittest cqueue)
target_include_directories(cqueue_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest)
target_compile_definitions(cqueue_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
