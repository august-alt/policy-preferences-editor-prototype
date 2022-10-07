find_package(Qt5 COMPONENTS Core Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_SOURCE_DIR}/src/gui)

set(TEST_NAME concatenatetreesproxymodeltest)

set(SOURCES
    concatenatetreesproxymodeltest.cpp
)

set(HEADERS
    concatenatetreesproxymodeltest.h
)

add_executable(${TEST_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${TEST_NAME} ${PREFERENCES_EDITOR_LIBRARIES} Qt5::Core Qt5::Test)
add_preferences_editor_test(plugins.${TEST_NAME} ${TEST_NAME})
