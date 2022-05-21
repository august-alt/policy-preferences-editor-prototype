set(XSD_FILES
    commonschema.xsd
    drivesschema.xsd
)

# Unable to generate files in current directory
generate_code_from_xsd(SOURCES ${XSD_FILES})

message("List of generated files: " ${SOURCES})

add_library(static_xsd_library STATIC ${SOURCES})
target_link_libraries(static_xsd_library xerces-c)
