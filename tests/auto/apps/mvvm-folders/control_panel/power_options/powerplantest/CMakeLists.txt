find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    powerplanwidgettest.h
)

set(SOURCES
    powerplanwidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(powerplanwidgettest ${SOURCES})
target_link_libraries(powerplanwidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.powerplanwidgettest powerplanwidgettest)

