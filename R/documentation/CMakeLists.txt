# find installed debian Quarto package to render documentation. Ref: https://quarto.org/
find_program(QUARTO quarto REQUIRED)

add_custom_target(build_documentation
    COMMENT "Building documentation"
    COMMAND ${QUARTO} render "${CMAKE_CURRENT_SOURCE_DIR}" --output-dir "${PROJECT_SOURCE_DIR}/build/publish" --quiet
    COMMAND echo "Documentation is available in build/publish/index.html"
) # COMMENT or COMMAND

set_property(TARGET build_documentation
           PROPERTY ADDITIONAL_CLEAN_FILES "${PROJECT_SOURCE_DIR}/build/publish")

find_program(BROWSER sensible-browser)

add_custom_target(display_documentation
    COMMENT "Opening documentation in default web browser"
    COMMAND ${BROWSER} "${PROJECT_SOURCE_DIR}/build/publish/index.html"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    DEPENDS build_documentation
)
