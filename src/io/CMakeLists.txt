find_package(Qt5 COMPONENTS Core REQUIRED)

set(HEADERS
    genericfile.h
    genericfile.inl
    genericreader.h
    genericreader.inl
    inifile.h
    io.h
    policyfileformat.h
    policyfileformat.inl
    registryfileformat.h
    registryfileformat.inl
)

set(SOURCES    
    inifile.cpp
    io.cpp
)

add_definitions(
    -DPREFERENCES_EDITOR_IO_LIBRARY
)

add_preferences_editor_library(preferences_editor-io ${SOURCES})
target_link_libraries(preferences_editor-io Qt5::Core)
