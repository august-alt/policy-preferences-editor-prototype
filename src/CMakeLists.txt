# set compiler options
if (CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32 AND NOT PREFERENCES_EDITOR_SETUP_CODECOVERAGE)
  if(${CMAKE_SYSTEM_PROCESSOR} STREQUAL "e2k")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -fvisibility=default -pedantic -Wall")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -fvisibility=hidden -fvisibility-inlines-hidden -pedantic -Wall\
        -Wextra -Wno-long-long -Weffc++ -Werror -Wall -Wextra -pedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
        -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast \
        -Woverloaded-virtual -Wredundant-decls -Wshadow -Wstrict-null-sentinel -Wundef \
        -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option")
  endif()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frelaxed-template-template-args")
endif()

macro(add_preferences_editor_library name)
  # add library
  add_library(${name} SHARED ${ARGN})

  # add install target
  install(TARGETS ${name} DESTINATION ${CMAKE_INSTALL_LIBDIR}
      PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

  # copy library into build directory
  add_custom_command(TARGET ${name} POST_BUILD COMMAND
      ${CMAKE_COMMAND} ARGS -E copy
        $<TARGET_FILE:${name}>
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/$<TARGET_FILE_NAME:${name}>
      COMMENT "Copying library ${name} to output directory")

endmacro(add_preferences_editor_library)

add_subdirectory(apps)
add_subdirectory(core)
add_subdirectory(gui)
add_subdirectory(io)
add_subdirectory(plugins)
