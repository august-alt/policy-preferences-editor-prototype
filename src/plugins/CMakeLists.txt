macro(add_preferences_editor_plugin name)
  # add plugin
  add_library(${name} SHARED ${ARGN})

  # add install target
  install(TARGETS ${name} DESTINATION ${CMAKE_INSTALL_LIBDIR}/preferences_editor/plugins
      PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

  # copy plugin into build directory
  add_custom_command(TARGET ${name} POST_BUILD COMMAND
      ${CMAKE_COMMAND} ARGS -E copy
        $<TARGET_FILE:${name}>
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/preferences_editor/plugins/$<TARGET_FILE_NAME:${name}>
      COMMENT "Copying plugin ${name} to ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}/preferences_editor/plugins directory")

endmacro(add_preferences_editor_plugin)

add_subdirectory(common)
add_subdirectory(ini)
add_subdirectory(preferences)
add_subdirectory(storage)
add_subdirectory(scripts)
add_subdirectory(administrative_templates)
