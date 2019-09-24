project(taglib-node-binding-native)

set(TAGLIB_VERSION "v1.11.1")
include(ExternalProject)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(SUPPORT_LARGE_FILES ON)
if(UNIX AND NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W0 /D_WIN32_WINNT=0x0601")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.10")
endif()

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

link_directories(${CMAKE_SOURCE_DIR}/taglib/lib)
include_directories(BEFORE ${CMAKE_JS_INC} ${CMAKE_SOURCE_DIR}/taglib/include ${CMAKE_SOURCE_DIR}/node_modules/node-addon-api)

file(GLOB SOURCE_FILES "src/*.cc" "src/*.h")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")

add_dependencies(${PROJECT_NAME} taglib)

target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB} tag)