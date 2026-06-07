# Dakata99

# Add AVL as a static library
add_library(avl STATIC src/AVL.cpp)
target_include_directories(avl PUBLIC inc src .. ../Binary/Linked/inc ../BST/inc)

# Add test
add_executable(avl_unittest test/test.cpp)
target_link_libraries(avl_unittest avl Utils)
target_include_directories(avl_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(avl_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
