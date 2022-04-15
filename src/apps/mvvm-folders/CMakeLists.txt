find_package(MVVM REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    commonitem.h
    commonview.h
    containeritem.h
    foldercontaineritem.h
    folderitem.h
    folderitemcontroller.h
    folderview.h
    preferenceswidget.h
)

set(SOURCES
    commonitem.cpp
    commonview.cpp
    containeritem.cpp
    foldercontaineritem.cpp
    folderitem.cpp
    folderitemcontroller.cpp
    folderview.cpp
    folderviewslots.cpp
    main.cpp
    preferenceswidget.cpp
)

set(UI_FORMS
    commonview.ui
    foldersview.ui
    preferenceswidget.ui
)

set(SOURCES ${SOURCES} ${HEADERS} ${UI_FORMS})

add_preferences_editor_executable(mvvm-folders ${SOURCES})

target_link_libraries(mvvm-folders Qt5::Core Qt5::Widgets)
target_link_libraries(mvvm-folders ${PREFERENCES_EDITOR_LIBRARIES})
target_link_libraries(mvvm-folders ${MVVM_LIBRARIES})
