find_package(PREFERENCES_EDITOR COMPONENTS io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

set(HEADERS
    iniformat.h
)

set(SOURCES
    iniformat.cpp
    iniplugin.cpp
)

add_preferences_editor_plugin(inifile-plugin ${SOURCES})
target_link_libraries(inifile-plugin Qt5::Core)
target_link_libraries(inifile-plugin ${PREFERENCES_EDITOR_LIBRARIES})
