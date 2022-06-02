find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    scheduleactionwin7widgettest.h
)

set(SOURCES
    scheduleactionwin7widgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(scheduleactionwin7widgettest ${SOURCES})
target_link_libraries(scheduleactionwin7widgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.scheduleactionwin7widgettest scheduleactionwin7widgettest)

