find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    shortcutswidgettest.h
)

set(SOURCES
    shortcutswidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(shortcutswidgettest ${SOURCES})
target_link_libraries(shortcutswidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(shortcutswidgettest mvvm-folders_static)

add_preferences_editor_test(preferences.shortcutswidgettest shortcutswidgettest)

