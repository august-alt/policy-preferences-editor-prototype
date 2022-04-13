find_package(MVVM REQUIRED)

set(HEADERS
)

set(SOURCES
    main.cpp
)

add_preferences_editor_executable(mvvm-folders ${SOURCES})

target_link_libraries(mvvm-folders Qt5::Core Qt5::Widgets)
target_link_libraries(mvvm-folders ${PREFERENCES_EDITOR_LIBRARIES})
target_link_libraries(mvvm-folders ${MVVM_LIBRARIES})
