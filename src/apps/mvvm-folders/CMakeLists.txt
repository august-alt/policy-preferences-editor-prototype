find_package(MVVM REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    common/commonitem.h
    common/commonutils.h
    common/commonview.h
    common/preferencecategoryitem.h
    common/preferencesdialog.h
    common/preferencesmodel.h
    common/propertieswidget.h
    common/tabledetailswidget.h
    common/widgetfactory.h

    drives/drivesitem.h
    drives/drivescontaineritem.h
    drives/driveswidget.h

    folders/foldercontaineritem.h
    folders/folderitem.h
    folders/folderitemcontroller.h
    folders/folderwidget.h

    files/filesitem.h
    files/filescontaineritem.h
    files/fileswidget.h

    ini/iniitem.h
    ini/inicontaineritem.h
    ini/iniwidget.h

    interfaces/containeriteminterface.h
    interfaces/preferenceswidgetinterface.h
    interfaces/widgetfactoryinterface.h

    registry/registrycontaineritem.h
    registry/registryitem.h
    registry/registrywidget.h

    shares/sharesitem.h
    shares/sharescontaineritem.h
    shares/shareswidget.h

    shortcuts/shortcutsitem.h
    shortcuts/shortcutscontaineritem.h
    shortcuts/shortcutswidget.h

    variables/variablesitem.h
    variables/variablescontaineritem.h
    variables/variableswidget.h

    mainwindow.h
    preferencestreemodel.h

    preferenceswidget.h
)

set(SOURCES
    common/commonitem.cpp
    common/commonutils.cpp
    common/commonview.cpp
    common/preferencecategoryitem.cpp
    common/preferencesdialog.cpp
    common/preferencesmodel.cpp
    common/propertieswidget.cpp
    common/tabledetailswidget.cpp
    common/widgetfactory.cpp

    drives/drivesitem.cpp
    drives/drivescontaineritem.cpp
    drives/driveswidget.cpp
    drives/driveswidgetslots.cpp

    folders/foldercontaineritem.cpp
    folders/folderitem.cpp
    folders/folderitemcontroller.cpp
    folders/folderwidget.cpp
    folders/folderviewslots.cpp

    files/filesitem.cpp
    files/filescontaineritem.cpp
    files/fileswidget.cpp
    files/fileswidgetslots.cpp

    ini/iniitem.cpp
    ini/inicontaineritem.cpp
    ini/iniwidget.cpp
    ini/iniwidgetslots.cpp

    registry/registrycontaineritem.cpp
    registry/registryitem.cpp
    registry/registrywidget.cpp
    registry/registrywidgetslots.cpp

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
    mainwindow.cpp
    preferencestreemodel.cpp

    preferenceswidget.cpp
)

set(UI_FORMS
    common/commonview.ui
    common/preferencesdialog.ui
    common/propertieswidget.ui
    common/tabledetailswidget.ui
    drives/driveswidget.ui
    folders/folderswidget.ui
    files/fileswidget.ui
    ini/iniwidget.ui
    registry/registrywidget.ui
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
