find_package(PREFERENCES_EDITOR COMPONENTS io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

set(HEADERS
    admxformat.h
)

set(SOURCES
    admxformat.cpp
    admxplugin.cpp
)

add_preferences_editor_plugin(admx-plugin ${SOURCES})
target_link_libraries(admx-plugin Qt5::Core)
target_link_libraries(admx-plugin ${PREFERENCES_EDITOR_LIBRARIES} policy-common)
target_link_libraries(admx-plugin xerces-c)
