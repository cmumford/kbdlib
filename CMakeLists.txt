cmake_minimum_required(VERSION 3.5)

if (NOT DEFINED PROJECT_NAME)
  include($ENV{IDF_PATH}/tools/cmake/project.cmake)
  project(keylib)
endif (NOT DEFINED PROJECT_NAME)
