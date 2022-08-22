cmake_minimum_required(VERSION 3.14)

project("preferences editor")

set(PREFERENCES_EDITOR_VERSION_MAJOR 0)
set(PREFERENCES_EDITOR_VERSION_MINOR 1)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(PREFERENCES_EDITOR_DIR "${CMAKE_BINARY_DIR}")

include(TranslationUtils)
include(FindXsd)

if(UNIX)
  include(GNUInstallDirs)
else()
  if (WIN32)
    set(${CMAKE_INSTALL_LIBDIR} "lib")
    set(${CMAKE_INSTALL_DATADIR} "share")
    set(${CMAKE_INSTALL_INCLUDEDIR} "include")
    set(${CMAKE_INSTALL_BINDIR} "bin")
    message(STATUS "Setting installation destination on Windows to: ${CMAKE_INSTALL_PREFIX}")
  else()
    message(FATAL_ERROR "System not UNIX nor WIN32 - not implemented yet")
  endif()
endif()

# configure and install Config.cmake file
configure_file(
    "${CMAKE_MODULE_PATH}/PREFERENCES_EDITORConfig.cmake.in"
    "${CMAKE_BINARY_DIR}/PREFERENCES_EDITORConfig.cmake"
    IMMEDIATE @ONLY)

# export the PREFERENCES_EDITOR package
export(PACKAGE PREFERENCES_EDITOR)

option(PREFERENCES_EDITOR_BUILD_TESTS "Build the preference editor tests." OFF)
option(PREFERENCES_EDITOR_SETUP_CODECOVERAGE "Setup coverege for preference editor." OFF)

if (PREFERENCES_EDITOR_SETUP_CODECOVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

function(project_testcoverage_setup)
    if (PREFERENCES_EDITOR_BUILD_TESTS)
        setup_target_for_coverage_lcov(NAME coverage
            EXECUTABLE ctest -j 4
            EXCLUDE
                "${PROJECT_SOURCE_DIR}/tests/*"
                "${PROJECT_SOURCE_DIR}/src/apps/mvvm-folders/schemas/*"
                "${PROJECT_SOURCE_DIR}/src/core/*"
                "${PROJECT_SOURCE_DIR}/src/gui/*"
                "${PROJECT_SOURCE_DIR}/src/io/*"
                "${PROJECT_SOURCE_DIR}/src/plugins/*"
                "**CompilerId*" "/usr/*"  "${CMAKE_BINARY_DIR}/*"
            )
    endif()
endfunction()

if (PREFERENCES_EDITOR_SETUP_CODECOVERAGE)
    project_testcoverage_setup()
endif()
