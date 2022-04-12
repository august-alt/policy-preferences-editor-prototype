find_package(PREFERENCES_EDITOR COMPONENTS io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(HEADERS
    modelbuilder.h
    variablesroles.h
    variablesschema.h
    variableswidget.h
)

set(SOURCES
    modelbuilder.cpp
    variablesschema.cpp
    variableswidget.cpp    
)

set(UI_FORMS
    variableswidget.ui
)

set(MOC_HEADERS
    variableswidget.h
)

qt5_wrap_ui(UI_SOURCES ${UI_FORMS})
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})

add_preferences_editor_plugin(variables-plugin ${UI_SOURCES} ${MOC_SOURCES} ${SOURCES})
target_link_libraries(variables-plugin Qt5::Core Qt5::Widgets)
target_link_libraries(variables-plugin ${PREFERENCES_EDITOR_LIBRARIES})
target_link_libraries(variables-plugin xerces-c)
