# TODO: make build system automatically download needed tools

# How to use?
## clang-format --style="{BasedOnStyle: Google, IndentWidth: 4, TabWidth: 4}" -i <file>
find_program(CLANG_FORMAT clang-format REQUIRED)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/STL/*.h
    ${PROJECT_SOURCE_DIR}/STL/*.cpp
    ${PROJECT_SOURCE_DIR}/STL/*.hpp
    ${PROJECT_SOURCE_DIR}/Utils/Utils.cpp
    ${PROJECT_SOURCE_DIR}/Utils/Utils.hpp
)

add_custom_target(
    format
    COMMAND ${CLANG_FORMAT} --verbose --Werror -i ${SOURCE_FILES}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
