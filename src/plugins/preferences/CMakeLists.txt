find_package(PREFERENCES_EDITOR COMPONENTS core io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/src/core")

set(HEADERS
    preferencessnapin.h
)

set(SOURCES
    preferencessnapin.cpp
    preferencesplugin.cpp
)

add_preferences_editor_plugin(preferences-plugin ${SOURCES})
target_link_libraries(preferences-plugin Qt5::Core)
target_link_libraries(preferences-plugin ${PREFERENCES_EDITOR_LIBRARIES})
