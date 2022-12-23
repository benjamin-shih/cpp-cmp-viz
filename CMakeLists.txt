cmake_minimum_required(VERSION 3.1...3.25)
project(
  CPPViz 
  VERSION 1.0
  LANGUAGES CXX)
find_package(Matplot++ REQUIRED)

add_executable(test test.cpp)

target_link_libraries(test Matplot++::matplot)
