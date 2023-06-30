find_program(PDFLATEX pdflatex REQUIRED)

add_custom_target(build_tex
    COMMENT "Building TeX files"
    COMMAND ${PDFLATEX} main.tex -halt-on-error -file-line-error
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

find_program(EVINCE evince REQUIRED)

add_custom_target(open_pdf
    COMMENT "Opening main.pdf file"
    COMMAND ${EVINCE} main.pdf
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS build_tex
)
