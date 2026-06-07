# Dakata99

# Add GMatrix as a static library
add_library(gmatrix STATIC src/GMatrix.cpp)
target_include_directories(gmatrix PUBLIC inc src ..)

# Add test
add_executable(gmatrix_unittest test/test.cpp)
target_link_libraries(gmatrix_unittest gmatrix Utils)
target_include_directories(gmatrix_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(gmatrix_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
