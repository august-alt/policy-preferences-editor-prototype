find_package(PREFERENCES_EDITOR COMPONENTS io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

set(HEADERS
    admlformat.h
)

set(SOURCES
    admlformat.cpp
    admlplugin.cpp
)

add_preferences_editor_plugin(adml-plugin ${SOURCES})
target_link_libraries(adml-plugin Qt5::Core)
target_link_libraries(adml-plugin ${PREFERENCES_EDITOR_LIBRARIES} policy-common)
target_link_libraries(adml-plugin xerces-c)
