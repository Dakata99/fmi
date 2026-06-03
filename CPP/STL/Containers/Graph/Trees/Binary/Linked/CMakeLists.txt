# Dakata99

# Add BTree as a static library
add_library(btree STATIC src/BTree.cpp)
target_include_directories(btree PUBLIC inc src)

# Add test
add_executable(btree_unittest test/test.cpp)
target_link_libraries(btree_unittest btree Utils)
target_include_directories(btree_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest)
target_compile_definitions(btree_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
