find_package(MVVM REQUIRED)

find_package(PREFERENCES_EDITOR COMPONENTS core io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

set(PLUGIN_NAME administrative-templates-plugin)

include_directories("${CMAKE_SOURCE_DIR}/src/core")

set(HEADERS
    administrativetemplatessnapin.h
)

set(SOURCES
    administrativetemplatessnapin.cpp
    administrativetemplatesplugin.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_preferences_editor_plugin(${PLUGIN_NAME} ${SOURCES})
target_link_libraries(${PLUGIN_NAME} Qt5::Core)
target_link_libraries(${PLUGIN_NAME} ${PREFERENCES_EDITOR_LIBRARIES})
