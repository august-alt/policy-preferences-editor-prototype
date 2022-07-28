find_package(PREFERENCES_EDITOR COMPONENTS core io gui REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/src/core")

set(HEADERS
    scriptssnapin.h
)

set(SOURCES
    scriptssnapin.cpp
    scriptsplugin.cpp
)

add_preferences_editor_plugin(scripts-plugin ${SOURCES})
target_link_libraries(scripts-plugin Qt5::Core)
target_link_libraries(scripts-plugin ${PREFERENCES_EDITOR_LIBRARIES})
