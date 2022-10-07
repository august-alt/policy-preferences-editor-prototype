find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    variableswidgettest.h
)

set(SOURCES
    variableswidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(variableswidgettest ${SOURCES})
target_link_libraries(variableswidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(variableswidgettest mvvm-folders_static)
target_link_libraries(variableswidgettest policy-common)

add_preferences_editor_test(preferences.variableswidgettest variableswidgettest)

