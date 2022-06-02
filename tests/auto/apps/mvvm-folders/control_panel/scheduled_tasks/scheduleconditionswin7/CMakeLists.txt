find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    scheduleconditionswin7widgettest.h
)

set(SOURCES
    scheduleconditionswin7widgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(scheduleconditionswin7widgettest ${SOURCES})
target_link_libraries(scheduleconditionswin7widgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.scheduleconditionswin7widgettest scheduleconditionswin7widgettest)

