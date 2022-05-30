find_package(PREFERENCES_EDITOR COMPONENTS gui model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Gui Test REQUIRED)
set(QT_USE_QTTEST TRUE)

include_directories(${CMAKE_SOURCE_DIR}/src/apps/mvvm-folders)

add_subdirectory(mvvm-folders)
