find_package(PREFERENCES_EDITOR COMPONENTS io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(HEADERS    
    drivesschema.h
    driveswidget.h
    modelbuilder.h
)

set(SOURCES
    drivesschema.cpp
    driveswidget.cpp
    modelbuilder.cpp
)

set(UI_FORMS
    driveswidget.ui
)

set(MOC_HEADERS
    driveswidget.h
)

qt5_wrap_ui(UI_SOURCES ${UI_FORMS})
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})

add_preferences_editor_plugin(drives-plugin ${UI_SOURCES} ${MOC_SOURCES} ${SOURCES})
target_link_libraries(drives-plugin Qt5::Core Qt5::Widgets)
target_link_libraries(drives-plugin ${PREFERENCES_EDITOR_LIBRARIES})
target_link_libraries(drives-plugin xerces-c)
