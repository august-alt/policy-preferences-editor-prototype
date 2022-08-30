find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    localgroupwidgettest.h
)

set(SOURCES
    localgroupwidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(localgroupwidgettest ${SOURCES})
target_link_libraries(localgroupwidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(localgroupwidgettest mvvm-folders_static)

add_preferences_editor_test(preferences.localgroupwidgettest localgroupwidgettest)

