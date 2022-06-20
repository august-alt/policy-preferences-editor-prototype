find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES_WIDGET
    iniwidgettest.h
    iniwidgettest.cpp
)

add_executable(iniwidgettest ${SOURCES_WIDGET})
target_link_libraries(iniwidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(iniwidgettest mvvm-folders_static)

add_preferences_editor_test(preferences.iniwidgettest iniwidgettest)

set(SOURCES_MODEL
    inimodeltest.h
    inimodeltest.cpp
)

add_executable(inimodeltest ${SOURCES_MODEL})
target_link_libraries(inimodeltest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(inimodeltest mvvm-folders_static)

add_preferences_editor_test(preferences.inimodeltest inimodeltest)

