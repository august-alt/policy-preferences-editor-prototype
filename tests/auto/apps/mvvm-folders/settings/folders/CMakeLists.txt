find_package(Qt5 COMPONENTS Core Gui Widgets Test REQUIRED)

find_package(XercesC REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    folderwidgettest.h
)

set(SOURCES
    folderwidgettest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(folderwidgettest ${SOURCES})
target_link_libraries(folderwidgettest Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Test XercesC::XercesC)
target_link_libraries(folderwidgettest mvvm-folders_static)
target_link_libraries(folderwidgettest policy-common)

add_preferences_editor_test(preferences.folderwidgettest folderwidgettest)
