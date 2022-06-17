find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    driveswidgettest.h
)

set(SOURCES
    driveswidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(driveswidgettest ${SOURCES})

target_link_libraries(driveswidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(driveswidgettest mvvm-folders_static)
target_link_libraries(driveswidgettest policy-common)

add_preferences_editor_test(preferences.driveswidgettest driveswidgettest)

