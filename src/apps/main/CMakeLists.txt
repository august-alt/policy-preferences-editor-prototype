set(HEADERS
)

set(SOURCES
    main.cpp
)

add_preferences_editor_executable(main ${SOURCES})

target_link_libraries(main Qt5::Core Qt5::Widgets)
target_link_libraries(main ${PREFERENCES_EDITOR_LIBRARIES})

