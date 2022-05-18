find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    poweroptionswidgettest.h
)

set(SOURCES
    poweroptionswidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(poweroptionswidgettest ${SOURCES})
target_link_libraries(poweroptionswidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.poweroptionswidgettest poweroptionswidgettest)

