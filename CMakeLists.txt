cmake_minimum_required(VERSION 3.1)
project(taglib-node-binding-native)

set(CMAKE_CXX_STANDARD 11)

include(./config/common.cmake)
include(./config/napi.cmake)
include(./config/taglib.cmake)

set(TAGLIB_VERSION "v1.11.1")
include(ExternalProject)

#set(CMAKE_VERBOSE_MAKEFILE OFF)
#set(SUPPORT_LARGE_FILES ON)
if(UNIX AND NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++11")
elseif(MSVC)
  #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W0 /D_WIN32_WINNT=0x0601")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.10")
endif()

file(GLOB SOURCE_FILES "src/*.cc" "src/*.h")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

AddCommonConfig(${PROJECT_NAME})
AddNapiSupport(${PROJECT_NAME})
AddTaglibSupport(${PROJECT_NAME})

add_dependencies(${PROJECT_NAME} taglib)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_JS_INC})
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
