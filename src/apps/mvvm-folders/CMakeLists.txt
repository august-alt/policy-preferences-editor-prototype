find_package(MVVM REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    attributes/attributesitem.h

    common/commonitem.h
    common/commonutils.h
    common/commonview.h
    common/preferencecategoryitem.h
    common/preferencesdialog.h
    common/preferencesmodel.h
    common/propertieswidget.h
    common/tabledetailswidget.h
    common/widgetfactory.h

    datasource/datasourceitem.h
    datasource/datasourcecontaineritem.h
    datasource/datasourcewidget.h

    device/deviceitem.h
    device/devicecontaineritem.h
    device/devicewidget.h

    drives/drivesitem.h
    drives/drivescontaineritem.h
    drives/driveswidget.h

    folders/foldercontaineritem.h
    folders/folderitem.h
    folders/folderitemcontroller.h
    folders/folderwidget.h

    folder_options/folderoptionscontaineritem.h
    folder_options/folderoptionswidget.h
    folder_options/folderoptionsitem.h
    folder_options/openwithitem.h
    folder_options/openwithwidget.h

    files/filesitem.h
    files/filescontaineritem.h
    files/fileswidget.h

    ini/iniitem.h
    ini/inicontaineritem.h
    ini/iniwidget.h

    local_users_and_groups/baselocalitem.h
    local_users_and_groups/groupmemberdialog.h
    local_users_and_groups/groupmemberitem.h
    local_users_and_groups/groupmemberswidget.h
    local_users_and_groups/groupmemberscontaineritem.h
    local_users_and_groups/localgroupcontaineritem.h
    local_users_and_groups/localgroupitem.h
    local_users_and_groups/localgroupwidget.h
    local_users_and_groups/localuseritem.h
    local_users_and_groups/localuserwidget.h

    network_options/basenetworkitem.h
    network_options/dialupitem.h
    network_options/dialupwidget.h
    network_options/networkcontaineritem.h
    network_options/vpnitem.h
    network_options/vpnnetworkingwidget.h
    network_options/vpnoptionswidget.h
    network_options/vpnsecuritywidget.h
    network_options/vpnwidget.h

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
    attributes/attributesitem.cpp

    common/commonitem.cpp
    common/commonutils.cpp
    common/commonview.cpp
    common/preferencecategoryitem.cpp
    common/preferencesdialog.cpp
    common/preferencesmodel.cpp
    common/propertieswidget.cpp
    common/tabledetailswidget.cpp
    common/widgetfactory.cpp

    datasource/datasourceitem.cpp
    datasource/datasourcecontaineritem.cpp
    datasource/datasourcewidget.cpp
    datasource/datasourcewidgetslots.cpp

    device/deviceitem.cpp
    device/devicecontaineritem.cpp
    device/devicewidget.cpp

    drives/drivesitem.cpp
    drives/drivescontaineritem.cpp
    drives/driveswidget.cpp
    drives/driveswidgetslots.cpp

    folders/foldercontaineritem.cpp
    folders/folderitem.cpp
    folders/folderitemcontroller.cpp
    folders/folderwidget.cpp
    folders/folderviewslots.cpp

    folder_options/folderoptionscontaineritem.cpp
    folder_options/folderoptionswidget.cpp
    folder_options/folderoptionsitem.cpp
    folder_options/openwithitem.cpp
    folder_options/openwithwidget.cpp
    folder_options/openwithwidgetslots.cpp

    files/filesitem.cpp
    files/filescontaineritem.cpp
    files/fileswidget.cpp
    files/fileswidgetslots.cpp

    ini/iniitem.cpp
    ini/inicontaineritem.cpp
    ini/iniwidget.cpp
    ini/iniwidgetslots.cpp

    local_users_and_groups/baselocalitem.cpp
    local_users_and_groups/groupmemberdialog.cpp
    local_users_and_groups/groupmemberitem.cpp
    local_users_and_groups/groupmemberswidget.cpp
    local_users_and_groups/groupmemberswidgetslots.cpp
    local_users_and_groups/localgroupcontaineritem.cpp
    local_users_and_groups/localgroupitem.cpp
    local_users_and_groups/localgroupwidget.cpp
    local_users_and_groups/localgroupwidgetslots.cpp
    local_users_and_groups/localuseritem.cpp
    local_users_and_groups/localuserwidget.cpp
    local_users_and_groups/localuserwidgetslots.cpp

    network_options/basenetworkitem.cpp
    network_options/dialupitem.cpp
    network_options/dialupwidget.cpp
    network_options/dialupwidgetslots.cpp
    network_options/networkcontaineritem.cpp
    network_options/vpnitem.cpp
    network_options/vpnnetworkingwidget.cpp
    network_options/vpnoptionswidget.cpp
    network_options/vpnsecuritywidget.cpp
    network_options/vpnwidget.cpp
    network_options/vpnwidgetslots.cpp

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
    datasource/datasourcewidget.ui
    drives/driveswidget.ui
    device/devicewidget.ui
    folders/folderswidget.ui
    folder_options/folderoptionswidget.ui
    folder_options/openwithwidget.ui
    files/fileswidget.ui
    ini/iniwidget.ui
    local_users_and_groups/groupmemberswidget.ui
    local_users_and_groups/groupmemberdialog.ui
    local_users_and_groups/localuserwidget.ui
    local_users_and_groups/localgroupwidget.ui
    network_options/dialupwidget.ui
    network_options/vpnnetworkingwidget.ui
    network_options/vpnoptionswidget.ui
    network_options/vpnsecuritywidget.ui
    network_options/vpnwidget.ui
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
