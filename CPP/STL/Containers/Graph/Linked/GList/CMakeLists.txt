# Dakata99

# Add GList as a static library
add_library(glist STATIC src/GList.cpp)
target_include_directories(glist PUBLIC inc src ..)

# Add test
add_executable(glist_unittest test/test.cpp)
target_link_libraries(glist_unittest glist Utils)
target_include_directories(glist_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(glist_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
