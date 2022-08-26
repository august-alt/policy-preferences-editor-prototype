find_package(PREFERENCES_EDITOR COMPONENTS gui model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Gui Test REQUIRED)
set(QT_USE_QTTEST TRUE)

add_subdirectory(concatenatetreesproxymodel)
