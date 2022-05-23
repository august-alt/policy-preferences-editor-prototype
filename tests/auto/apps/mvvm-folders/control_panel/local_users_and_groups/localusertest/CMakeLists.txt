find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    localuserwidgettest.h
)

set(SOURCES
    localuserwidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(localuserwidgettest ${SOURCES})
target_link_libraries(localuserwidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
add_preferences_editor_test(preferences.localuserwidgettest localuserwidgettest)

