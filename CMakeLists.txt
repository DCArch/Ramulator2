cmake_minimum_required(VERSION 3.14)

project(
  Ramulator
  VERSION 2.0
  LANGUAGES CXX
)

#### Prompt the build type ####
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()
message("Configuring ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_Version}...")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DRAMULATOR_DEBUG")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
###############################

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

#### External libraries ####
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "Skip updating the external dependencies after populating them for the first time")

message("Configuring yaml-cpp...")
option(YAML_CPP_BUILD_CONTRIB "Enable yaml-cpp contrib in library" OFF)
option(YAML_CPP_BUILD_TOOLS "Enable parse tools" OFF)
option(YAML_BUILD_SHARED_LIBS "Build yaml-cpp as a shared library" OFF)
FetchContent_Declare(
  yaml-cpp                             
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG        yaml-cpp-0.7.0                        
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/ext/yaml-cpp
)
FetchContent_MakeAvailable(yaml-cpp)
include_directories(${yaml-cpp_SOURCE_DIR}/include)
message("Done configuring yaml-cpp.")

message("Configuring fmt...")
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        10.2.1    
  SOURCE_DIR     ${CMAKE_SOURCE_DIR}/ext/fmt
)
FetchContent_MakeAvailable(fmt)
include_directories(${fmt_SOURCE_DIR}/include)
message("Done configuring fmt.")

message("Configuring argparse...")
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
    GIT_TAG        v2.9     
    SOURCE_DIR     ${CMAKE_SOURCE_DIR}/ext/argparse
)
FetchContent_MakeAvailable(argparse)
include_directories(${argparse_SOURCE_DIR}/include)
message("Done configuring argparse.")
##################################

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(ramulator STATIC)
set_target_properties(ramulator PROPERTIES
  LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}
)
target_link_libraries(
  ramulator 
  PUBLIC yaml-cpp
  PUBLIC fmt
)

install(TARGETS ramulator
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install (FILES
         src/frontend/frontend.h
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/ramulator/frontend)
install (FILES
         src/base/config.h
         src/base/stats.h
         src/base/type.h
         src/base/serialization.h
         src/base/exception.h
         src/base/param.h
         src/base/debug.h
         src/base/request.h
         src/base/utils.h
         src/base/base.h
         src/base/factory.h
         src/base/clocked.h
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/ramulator/base)
install (FILES
         src/memory_system/memory_system.h
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include/ramulator/memory_system)

add_executable(ramulator-exe)
target_link_libraries(
  ramulator-exe 
  # PRIVATE -Wl,--whole-archive ramulator -Wl,--no-whole-archive 
  PRIVATE ramulator
  PRIVATE argparse
)

set_target_properties(
  ramulator-exe
  PROPERTIES 
  OUTPUT_NAME ramulator2
)

add_subdirectory(src)
