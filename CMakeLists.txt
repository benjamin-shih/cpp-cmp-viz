cmake_minimum_required(VERSION 3.1...3.25)

project(
  CPPViz
  VERSION 1.1
  DESCRIPTION "C++ Numerics and Visualization"
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_EXTENSIONS OFF)
  # set(CMAKE_VERBOSE_MAKEFILE ON)
  set(PYBIND11_PYTHON_VERSION 3.6)
  set(CMAKE_CXX_FLAGS "-Wall -Wextra")
  set(Boost_USE_STATIC_LIBS OFF)
  set(Boost_USE_MULTITHREADED ON)
  set(Boost_USE_STATIC_RUNTIME OFF)
  include(CTest)
endif()

include(FetchContent)

find_package(Boost 1.80.0 COMPONENTS random)
find_package(Matplot++ REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(pybind11 REQUIRED)
find_package(xtensor REQUIRED)

add_subdirectory(src)
add_subdirectory(apps)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
