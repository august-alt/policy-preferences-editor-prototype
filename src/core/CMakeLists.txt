find_package(Qt5 COMPONENTS Core Gui REQUIRED)

set(HEADERS
    common.h
    core.h
    plugin.h
    pluginstorage.h    
)

set(SOURCES
    core.cpp
    plugin.cpp
    pluginstorage.cpp    
)

add_definitions(
    -DPREFERENCES_EDITOR_CORE_LIBRARY
)

add_preferences_editor_library(preferences_editor-core ${SOURCES})
target_link_libraries(preferences_editor-core Qt5::Core Qt5::Gui)
