set(XSD_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/commonschema.xsd"
    "${CMAKE_CURRENT_SOURCE_DIR}/drivesschema.xsd"
)

foreach(FILE ${XSD_FILES})
    string(REGEX REPLACE "[.]xsd" ".h" HEADER ${FILE})
    set(HEADERS ${HEADERS} ${HEADER})
endforeach()

foreach(FILE ${XSD_FILES})
    string(REGEX REPLACE "[.]xsd" ".cpp" SOURCE ${FILE})
    set(SOURCES ${SOURCES} ${SOURCE})
endforeach()

set(OUT_FILES
    ${HEADERS}
    ${SOURCES}
)

set(XSD_FLAGS cxx-tree
    --generate-doxygen
    --generate-ostream
    --generate-polymorphic
    --polymorphic-type-all
    --generate-wildcard
    --cxx-suffix .cpp
    --hxx-suffix .h
    --std c++11
    --type-naming ucc
    --root-element-all
)

add_custom_command(
    OUTPUT ${OUT_FILES}
    COMMAND ${XSDCXX_EXECUTABLE} ${XSD_FLAGS} ${XSD_FILES}
    DEPENDS ${XSD_FILES}
    COMMENT "Running ${XSDCXX_EXECUTABLE} ${XSD_FLAGS} ${XSD_FILES}"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND_EXPAND_LISTS
)

add_library(static_xsd_library STATIC ${OUT_FILES})
