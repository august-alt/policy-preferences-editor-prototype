find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    vpnoptionswidgettest.h
)

set(SOURCES
    vpnoptionswidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(vpnoptionswidgettest ${SOURCES})
target_link_libraries(vpnoptionswidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.vpnoptionswidgettest vpnoptionswidgettest)

