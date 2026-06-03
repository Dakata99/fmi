<<<<<<< HEAD
# Dakata99

# Add Tree as a static library
add_library(tree STATIC src/Tree.cpp)
target_include_directories(tree PUBLIC inc src)

# Add test
add_executable(tree_unittest test/test.cpp)
target_link_libraries(tree_unittest tree Utils)
target_include_directories(tree_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(tree_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
=======
# dplyubenov

file(GLOB SOURCES src/*)

add_library(Tree STATIC ${SOURCES})
target_include_directories(Tree PRIVATE inc)
>>>>>>> 88ae05d (Updates)
