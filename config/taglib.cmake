function(AddTaglibSupport addonName)
  if(MSVC)
    set(WIN_OPTIONS "-DBUILD_SHARED_LIBS=OFF -DENABLE_STATIC_RUNTIME=ON")
  endif()

  ExternalProject_Add(
    taglib
    PREFIX "${CMAKE_SOURCE_DIR}/taglib"
    GIT_REPOSITORY https://github.com/taglib/taglib
    GIT_TAG ${TAGLIB_VERSION}
    INSTALL_DIR "${CMAKE_SOURCE_DIR}/taglib"
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/taglib" "${WIN_OPTIONS}"
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
    target_link_libraries(${addonName} PRIVATE ${CMAKE_JS_LIB} ${CMAKE_SOURCE_DIR}/taglib/lib/tag.lib)
  endif()

  if (UNIX AND NOT APPLE)
    target_link_libraries(${addonName} PRIVATE ${CMAKE_JS_LIB} ${CMAKE_SOURCE_DIR}/taglib/lib/libtag.a)
  endif()
endfunction(AddTaglibSupport addonName)