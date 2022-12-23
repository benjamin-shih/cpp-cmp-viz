cmake_minimum_required(VERSION 3.1...3.25)

project(
  CPPViz 
  VERSION 1.0
  LANGUAGES CXX)

find_package(Matplot++ REQUIRED)

file(GLOB SOURCES src/*.cpp)

foreach(srcfile ${SOURCES} )
    get_filename_component(EXECUTABLE_NAME ${srcfile} NAME_WE)
    add_executable( ${EXECUTABLE_NAME} ${srcfile} )
    target_link_libraries(${EXECUTABLE_NAME} Matplot++::matplot)
endforeach(srcfile ${SOURCES} )
