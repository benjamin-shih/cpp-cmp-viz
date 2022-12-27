cmake_minimum_required(VERSION 3.1...3.25)

project(
  CPPViz
  VERSION 1.0
  LANGUAGES CXX)

# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)
set(PYBIND11_PYTHON_VERSION 3.6)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.80.0 COMPONENTS random)
find_package(Matplot++ REQUIRED)
find_package(Eigen3 3.3 REQUIRED)
find_package(pybind11 REQUIRED)
find_package(xtensor REQUIRED)

pybind11_add_module(${PROJECT_NAME} src/pywrap.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
target_include_directories(${PROJECT_NAME} PRIVATE ${PYBIND11_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

file(GLOB SOURCES src/mesh.cpp src/rejection_sampling.cpp src/tensor.cpp)

foreach(srcfile ${SOURCES} )
    get_filename_component(EXECUTABLE_NAME ${srcfile} NAME_WE)
    include_directories(${Boost_INCLUDE_DIRS} ${xtensor_INCLUDE_DIRS})
    add_executable( ${EXECUTABLE_NAME} ${srcfile} )
    target_link_libraries(${EXECUTABLE_NAME} Matplot++::matplot Eigen3::Eigen ${Boost_LIBRARIES} xtensor)
endforeach(srcfile ${SOURCES} )
