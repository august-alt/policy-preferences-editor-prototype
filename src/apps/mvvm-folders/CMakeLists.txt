find_package(MVVM REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    common/commonitem.h
    common/commonutils.h
    common/commonview.h

    drives/drivesitem.h
    drives/drivescontaineritem.h
    drives/driveswidget.h

    folders/foldercontaineritem.h
    folders/folderitem.h
    folders/folderitemcontroller.h
    folders/folderview.h

    files/filesitem.h
    files/filescontaineritem.h
    files/fileswidget.h

    ini/iniitem.h
    ini/inicontaineritem.h
    ini/iniwidget.h

    shares/sharesitem.h
    shares/sharescontaineritem.h
    shares/shareswidget.h

    shortcuts/shortcutsitem.h
    shortcuts/shortcutscontaineritem.h
    shortcuts/shortcutswidget.h

    variables/variablesitem.h
    variables/variablescontaineritem.h
    variables/variableswidget.h

    preferenceswidget.h
)

set(SOURCES
    common/commonitem.cpp
    common/commonutils.cpp
    common/commonview.cpp

    drives/drivesitem.cpp
    drives/drivescontaineritem.cpp
    drives/driveswidget.cpp
    drives/driveswidgetslots.cpp

    folders/foldercontaineritem.cpp
    folders/folderitem.cpp
    folders/folderitemcontroller.cpp
    folders/folderview.cpp
    folders/folderviewslots.cpp

    files/filesitem.cpp
    files/filescontaineritem.cpp
    files/fileswidget.cpp
    files/fileswidgetslots.cpp

    ini/iniitem.cpp
    ini/inicontaineritem.cpp
    ini/iniwidget.cpp
    ini/iniwidgetslots.cpp

    shares/sharesitem.cpp
    shares/sharescontaineritem.cpp
    shares/shareswidget.cpp
    shares/shareswidgetslots.cpp

    shortcuts/shortcutsitem.cpp
    shortcuts/shortcutscontaineritem.cpp
    shortcuts/shortcutswidget.cpp
    shortcuts/shortcutswidgetslots.cpp

    variables/variablesitem.cpp
    variables/variablescontaineritem.cpp
    variables/variableswidget.cpp
    variables/variableswidgetslots.cpp

    main.cpp
    preferenceswidget.cpp
)

set(UI_FORMS
    common/commonview.ui
    drives/driveswidget.ui
    folders/foldersview.ui
    files/fileswidget.ui
    ini/iniwidget.ui
    shares/shareswidget.ui
    shortcuts/shortcutswidget.ui
    variables/variableswidget.ui
    preferenceswidget.ui
)

set(SOURCES ${SOURCES} ${HEADERS} ${UI_FORMS})

add_preferences_editor_executable(mvvm-folders ${SOURCES})

target_link_libraries(mvvm-folders Qt5::Core Qt5::Widgets)
target_link_libraries(mvvm-folders ${PREFERENCES_EDITOR_LIBRARIES})
target_link_libraries(mvvm-folders ${MVVM_LIBRARIES})
