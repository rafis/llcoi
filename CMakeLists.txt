cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmakemodules;${CMAKE_MODULE_PATH}")

include(FindPkgMacros)

getenv_path(OGRE_HOME)
getenv_path(OGRE_SDK)

# setup some possible locations for OGRE
if (WIN32)
  getenv_path(PROGRAMFILES)

  set(OGRE_ROOT_GUESSES
    ${ENV_PROGRAMFILES}/OGRE
    C:/OgreSDK
    ${ENV_OGRE_HOME}
    ${ENV_OGRE_SDK}
    ${OGRE_HOME}
    ${OGRE_SDK}
  )
elseif (UNIX)
  set(OGRE_ROOT_GUESSES
    /opt/ogre
    /opt/OGRE
    /usr/lib${LIB_SUFFIX}/ogre
    /usr/lib${LIB_SUFFIX}/OGRE
    /usr/local/lib${LIB_SUFFIX}/ogre
    /usr/local/lib${LIB_SUFFIX}/OGRE
    $ENV{HOME}/ogre
    $ENV{HOME}/OGRE
    ${ENV_OGRE_HOME}
    ${ENV_OGRE_SDK}
    ${OGRE_HOME}
    ${OGRE_SDK}
  )
endif ()

find_file(OGRE_CMAKE_MODULE_FILE NAMES cmake/FindOGRE.cmake CMake/FindOGRE.cmake PATHS ${OGRE_ROOT_GUESSES} NO_DEFAULT_PATH)

if(NOT OGRE_CMAKE_MODULE_FILE)
  message(FATAL_ERROR "failed to locate OGRE CMake module path. Try setting OGRE_HOME or OGRE_SDK in environment.")
endif()

get_filename_component(OGRE_CMAKE_MODULE_PATH ${OGRE_CMAKE_MODULE_FILE} PATH)

message(STATUS "OGRE CMake modules found in ${OGRE_CMAKE_MODULE_PATH}")

set(CMAKE_MODULE_PATH "${OGRE_CMAKE_MODULE_PATH};${CMAKE_MODULE_PATH}")

if (WIN32)
    set(Boost_USE_STATIC_LIBS TRUE)
    set(Boost_USE_MULTITHREADED TRUE)
    set(Boost_USE_STATIC_RUNTIME FALSE)
else ()
    set(Boost_USE_STATIC_LIBS FALSE)
    set(Boost_USE_MULTITHREADED TRUE)
    set(Boost_USE_STATIC_RUNTIME FALSE)
endif (WIN32)
find_package (OGRE REQUIRED)
find_package (OIS REQUIRED)

# do not default to empty build type
if (CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

# Specify build paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
if (WIN32 OR APPLE)
  if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # We don't want to install in default system location, install is really for the SDK, so call it that
    set(CMAKE_INSTALL_PREFIX
	  "${CMAKE_BINARY_DIR}/llcoi" CACHE PATH "${PROJECT_NAME} install prefix" FORCE
    )
  endif (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
endif(WIN32 OR APPLE)

add_definitions(-DLLCOI_BUILD_DYNAMIC)

add_subdirectory(interface)

option(LLCOI_BUILD_TEST "Build test for LLCOI" FALSE)
if(LLCOI_BUILD_TEST)
    option(LLCOI_TEST_USE_ALLEGRO "Build Test program with Allegro instead of OpenInput)" FALSE)
    option(LLCOI_TEST_USE_OPENINPUT "Build test program with OpenInput instead of OIS" FALSE)
    add_subdirectory(test)
endif()