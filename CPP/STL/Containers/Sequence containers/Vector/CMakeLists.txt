# Dakata99

# Add Vector as a static library
add_library(vector STATIC src/Vector.cpp)
target_include_directories(vector PUBLIC inc src)

# Add test
add_executable(vector_unittest test/test.cpp)
target_link_libraries(vector_unittest vector Utils)
target_include_directories(vector_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(vector_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
