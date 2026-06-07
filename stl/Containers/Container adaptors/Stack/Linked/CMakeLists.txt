# Dakata99

# Add Stack as a static library
add_library(lstack STATIC src/Stack.cpp)
target_include_directories(lstack PUBLIC inc src)

# Add test
add_executable(lstack_unittest test/test.cpp)
target_link_libraries(lstack_unittest lstack)
target_include_directories(lstack_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest)
target_compile_definitions(lstack_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
