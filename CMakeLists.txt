cmake_minimum_required(VERSION 3.5)

if(ESP_PLATFORM)

if (NOT DEFINED PROJECT_NAME)
  include($ENV{IDF_PATH}/tools/cmake/project.cmake)
  project(keylib)
endif (NOT DEFINED PROJECT_NAME)

else()  # ESP_PLATFORM

project(kbdlib VERSION 0.1 LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
  # This project requires C++11.
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif(NOT CMAKE_CXX_STANDARD)

set(KBDLIB_PUBLIC_INCLUDE_DIR "include/kbdlib")

add_library(kbdlib "")
target_sources(kbdlib
  PRIVATE
    "src/adp5589.cc"
    "src/lm8330.cc"

  # Only CMake 3.3+ supports PUBLIC sources in targets exported by "install".
  $<$<VERSION_GREATER:CMAKE_VERSION,3.2>:PUBLIC>
    "${KBDLIB_PUBLIC_INCLUDE_DIR}/adp5589.h"
    "${KBDLIB_PUBLIC_INCLUDE_DIR}/lm8330.h"
    "${KBDLIB_PUBLIC_INCLUDE_DIR}/tca8418.h"
)

target_include_directories(kbdlib
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

endif() # if(ESP_PLATFORM)
