# Dakata99

# Add SLList as a static library
add_library(sllist STATIC src/SLList.cpp)
target_include_directories(sllist PUBLIC inc src)

# Add test
add_executable(sllist_unittest test/test.cpp)
target_link_libraries(sllist_unittest sllist Utils)
target_include_directories(sllist_unittest PRIVATE ${PROJECT_SOURCE_DIR}/Utils/Doctest/doctest ${PROJECT_SOURCE_DIR}/Utils)
target_compile_definitions(sllist_unittest PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
