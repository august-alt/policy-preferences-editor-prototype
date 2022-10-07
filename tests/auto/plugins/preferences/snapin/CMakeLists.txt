find_package(Qt5 COMPONENTS Core Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_SOURCE_DIR}/src/plugins/preferences)

set(HEADERS
    preferencessnapintest.h
)

set(SOURCES
    preferencessnapintest.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_executable(preferencessnapintest ${SOURCES})
target_link_libraries(preferencessnapintest Qt5::Core Qt5::Test)
target_link_libraries(preferencessnapintest preferences-plugin)
add_preferences_editor_test(preferences.preferencessnapintest preferencessnapintest)

