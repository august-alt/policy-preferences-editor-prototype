find_package(Qt5 COMPONENTS Widgets Qml LinguistTools REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(HEADERS
    aboutdialog.h
    commandlineoptions.h
    commandlineparser.h
    editorpreferencesdialog.h
    gui.h
    filedialogutils.h
    listboxdialog.h
    mainwindow.h
    mainwindowsettings.h
    treevieweventfilter.h
)

set(SOURCES
    aboutdialog.cpp
    commandlineparser.cpp
    editorpreferencesdialog.cpp
    gui.cpp
    filedialogutils.cpp
    listboxdialog.cpp
    mainwindow.cpp
    mainwindowsettings.cpp
    treevieweventfilter.cpp
)

set(UI_FORMS
    aboutdialog.ui
    editorpreferencesdialog.ui
    listboxdialog.ui
    mainwindow.ui
)

set(MOC_HEADERS
    aboutdialog.h
    editorpreferencesdialog.h
    listboxdialog.h
    mainwindow.h
    mainwindowsettings.h
    treevieweventfilter.h
)

set(TS_FILES
    i18n/gui_en.ts
    i18n/gui_ru.ts
)

set(ICON_RESOURCES
    icon.qrc
)

set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_SOURCE_DIR})

qt5_add_translation(QM_FILES ${TS_FILES})

qt5_wrap_ui(UI_SOURCES ${UI_FORMS})
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})

add_definitions(
    -DPREFERENCES_EDITOR_GUI_LIBRARY
)

add_translation_resource(RESOURCES_SRC ${QM_FILES})

qt5_add_resources(LIB_RESOURCES ${RESOURCES_SRC} ${ICON_RESOURCES})

add_preferences_editor_library(preferences_editor-gui ${UI_SOURCES} ${MOC_SOURCES} ${SOURCES} ${LIB_RESOURCES})
target_link_libraries(preferences_editor-gui Qt5::Widgets Qt5::Qml)
target_link_libraries(preferences_editor-gui preferences_editor-core preferences_editor-io)
target_link_libraries(preferences_editor-gui smb-storage-static)
