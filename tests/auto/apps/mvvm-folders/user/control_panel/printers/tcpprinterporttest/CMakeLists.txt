find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    tcpprinterportwidgettest.h
)

set(SOURCES
    tcpprinterportwidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(tcpprinterportwidgettest ${SOURCES})
target_link_libraries(tcpprinterportwidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.tcpprinterportwidgettest tcpprinterportwidgettest)

