find_package(PREFERENCES_EDITOR COMPONENTS core io gui REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("${CMAKE_SOURCE_DIR}/src/core")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    scriptssnapin.h
    scriptswidget.h
    scriptspowershellwidget.h
)

set(SOURCES
    scriptssnapin.cpp
    scriptsplugin.cpp
    scriptswidget.cpp
    scriptspowershellwidget.cpp
)

set(UIFORMS
    scriptswidget.ui
    scriptsdialog.ui
    scriptspowershellwidget.ui
)

set(SOURCES ${SOURCES} ${HEADERS} ${UIFORMS})

add_preferences_editor_plugin(scripts-plugin ${SOURCES})
target_link_libraries(scripts-plugin Qt5::Core Qt5::Widgets)
target_link_libraries(scripts-plugin ${PREFERENCES_EDITOR_LIBRARIES})
