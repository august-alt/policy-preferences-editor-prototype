function(generate_code_from_xsd OUT_FILES)

set(IN_FILES ${ARGN})

string(REGEX REPLACE "[.]xsd" ".h "   HEADERS ${IN_FILES})
string(REGEX REPLACE "[.]xsd" ".cpp " SOURCES ${IN_FILES})

add_custom_command(
    OUTPUT ${HEADERS} ${SOURCES}
    COMMAND xsdcxx cxx-tree --generate-doxygen --generate-ostream
                            --generate-polymorphic --polymorphic-type-all --generate-wildcard --cxx-suffix .cpp
                            --hxx-suffix .h --std c++11 --type-naming ucc --root-element-all ${IN_FILES}
    DEPENDS ${IN_FILES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    VERBATIM
    USES_TERMINAL
)

set(${OUT_FILES} ${HEADERS} ${SOURCES} PARENT_SCOPE)

endfunction()
