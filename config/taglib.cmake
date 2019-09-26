function(AddTaglibSupport addonName)
  ExternalProject_Add(
    taglib
    PREFIX "${CMAKE_SOURCE_DIR}/taglib"
    GIT_REPOSITORY https://github.com/taglib/taglib
    GIT_TAG ${TAGLIB_VERSION}
    INSTALL_DIR "${CMAKE_SOURCE_DIR}/taglib"
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/taglib"
    CMAKE_CACHE_ARGS "-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true"
  )

  ExternalProject_Add_Step(
    taglib
    forcebuild
    COMMAND ${CMAKE_COMMAND} -E echo_append ""
    DEPENDEES configure
    DEPENDEES build
    ALWAYS 1
  )

  target_include_directories(${addonName} PRIVATE ${CMAKE_SOURCE_DIR}/taglib/include)

  if (WIN32)
    target_link_libraries(${addonName} ${CMAKE_SOURCE_DIR}/taglib/lib/tag.lib)
  elseif (UNIX AND NOT APPLE)
    target_link_libraries(${addonName} ${CMAKE_SOURCE_DIR}/taglib/lib/libtag.a)
  endif()

  add_definitions(-DTAGLIB_STATIC)
endfunction(AddTaglibSupport addonName)