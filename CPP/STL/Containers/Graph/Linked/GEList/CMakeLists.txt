# Dakata99

# Add GEList as a static library
add_library(gelist STATIC src/GEList.cpp)
target_include_directories(gelist PUBLIC inc src ..)

# Add test
add_executable(gelist_unittest test/test.cpp)
target_link_libraries(gelist_unittest gelist Utils)
target_include_directories(gelist_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(gelist_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
