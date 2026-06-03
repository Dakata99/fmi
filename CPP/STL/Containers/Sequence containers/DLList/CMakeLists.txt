# Dakata99

# Add DLList as a static library
add_library(dllist STATIC src/DLList.cpp)
target_include_directories(dllist PUBLIC inc src)

# Add test
add_executable(dllist_unittest test/test.cpp)
target_link_libraries(dllist_unittest dllist Utils)
target_include_directories(dllist_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(dllist_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
