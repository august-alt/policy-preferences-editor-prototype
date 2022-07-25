find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

file(GLOB HEADERS "*.h")

file(GLOB SOURCES "*.cpp")

file(GLOB UIFORMS "*.ui")

set(SOURCES ${HEADERS} ${SOURCES} ${UIFORMS})

add_definitions(
    -DPREFERENCES_EDITOR_CORE_LIBRARY
)

add_preferences_editor_library(preferences_editor-core ${SOURCES})
target_link_libraries(preferences_editor-core Qt5::Core Qt5::Gui Qt5::Widgets)
