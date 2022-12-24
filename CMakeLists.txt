cmake_minimum_required(VERSION 3.1...3.25)

project(
  CPPViz
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")

find_package(Matplot++ REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

file(GLOB SOURCES src/*.cpp)

foreach(srcfile ${SOURCES} )
    get_filename_component(EXECUTABLE_NAME ${srcfile} NAME_WE)
    add_executable( ${EXECUTABLE_NAME} ${srcfile} )
    target_link_libraries(${EXECUTABLE_NAME} Matplot++::matplot Eigen3::Eigen)
endforeach(srcfile ${SOURCES} )
