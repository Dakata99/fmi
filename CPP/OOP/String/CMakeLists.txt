# Dakata99

# Add String as a static library
add_library(string STATIC src/String.cpp)
target_include_directories(string PUBLIC inc src)

# Add test
add_executable(string_unittest test/test.cpp)
target_link_libraries(string_unittest string Utils)
target_include_directories(string_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(string_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
