# Dakata99

# Add BST as a static library
add_library(bst STATIC src/BST.cpp)
target_include_directories(bst PUBLIC inc src ../Binary/Linked/inc)

# Add test
add_executable(bst_unittest test/test.cpp)
target_link_libraries(bst_unittest bst Utils)
target_include_directories(bst_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(bst_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
