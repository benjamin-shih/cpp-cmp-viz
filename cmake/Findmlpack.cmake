#.rst:
# Findmlpack
# -------------
#
# Find mlpack
#
# Find the mlpack C++ library
#
# Using mlpack::
#
#   find_package(mlpack REQUIRED)
#   include_directories(${MLPACK_INCLUDE_DIRS})
#   add_executable(foo foo.cc)
#
# This module sets the following variables::
#
#   mlpack_FOUND - set to true if the library is found
#   MLPACK_INCLUDE_DIRS - list of required include directories
#   MLPACK_VERSION_MAJOR - major version number
#   MLPACK_VERSION_MINOR - minor version number
#   MLPACK_VERSION_PATCH - patch version number
#   MLPACK_VERSION_STRING - version number as a string (ex: "1.0.4")

include(FindPackageHandleStandardArgs)
# UNIX paths are standard, no need to specify them.
find_path(MLPACK_INCLUDE_DIR
    NAMES mlpack/core.hpp mlpack/prereqs.hpp
    PATHS "$ENV{ProgramFiles}/mlpack"
)

if(MLPACK_INCLUDE_DIR)
  # Read and parse mlpack version header file for version number
  file(STRINGS "${MLPACK_INCLUDE_DIR}/mlpack/core/util/version.hpp" _mlpack_HEADER_CONTENTS REGEX "#define MLPACK_VERSION_[A-Z]+ ")
  string(REGEX REPLACE ".*#define MLPACK_VERSION_MAJOR ([0-9]+).*" "\\1" MLPACK_VERSION_MAJOR "${_mlpack_HEADER_CONTENTS}")
  string(REGEX REPLACE ".*#define MLPACK_VERSION_MINOR ([0-9]+).*" "\\1" MLPACK_VERSION_MINOR "${_mlpack_HEADER_CONTENTS}")
  string(REGEX REPLACE ".*#define MLPACK_VERSION_PATCH \"?([0-9x]+).*" "\\1" MLPACK_VERSION_PATCH "${_mlpack_HEADER_CONTENTS}")

  unset(_mlpack_HEADER_CONTENTS)

  set(MLPACK_VERSION_STRING "${MLPACK_VERSION_MAJOR}.${MLPACK_VERSION_MINOR}.${MLPACK_VERSION_PATCH}")
endif()

#[[
mlpack lib in mlpack/version/lib?

find_library(MLPACK_LIBRARY
  NAMES mlpack
  PATHS "$ENV{ProgramFiles}/mlpack/${MLPACK_VERSION_STRING}/lib"  "$ENV{ProgramFiles}/mlpack/${MLPACK_VERSION_STRING}/lib64" "$ENV{ProgramFiles}/mlpack"
)
]]

find_package_handle_standard_args(mlpack
  REQUIRED_VARS MLPACK_INCLUDE_DIR MLPACK_VERSION_STRING #MLPACK_LIBRARY
)

if(mlpack_FOUND)
  set(MLPACK_INCLUDE_DIRS ${MLPACK_INCLUDE_DIR})
  # set(MLPACK_LIBRARIES ${MLPACK_LIBRARY})
endif()

# Hide internal variables
mark_as_advanced(MLPACK_INCLUDE_DIR) # MLPACK_LIBRARY)
