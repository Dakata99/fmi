# Dakata99

# Add Stack as a static library
add_library(cstack STATIC src/Stack.cpp)
target_include_directories(cstack PUBLIC inc src)

# Add test
add_executable(cstack_unittest test/test.cpp)
target_link_libraries(cstack_unittest cstack)
target_include_directories(cstack_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest)
target_compile_definitions(cstack_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
