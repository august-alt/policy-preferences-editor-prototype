find_package(Qt5 COMPONENTS Core REQUIRED)

set(HEADERS
    basetypes.h
    exceptionhandler.h
    policydefinitions.h
    policydefinitionfiles.h
)

set(SOURCES
    basetypes.cpp
    exceptionhandler.cpp
    policydefinitions.cpp
    policydefinitionfiles.cpp
)

add_library(policy-common STATIC ${SOURCES} ${HEADERS})
target_link_libraries(policy-common Qt5::Core)

target_include_directories(policy-common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
