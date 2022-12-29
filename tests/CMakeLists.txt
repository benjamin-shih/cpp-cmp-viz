FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)

add_executable(testlib testrej.cpp)
target_compile_features(testlib PRIVATE cxx_std_11)
target_link_libraries(testlib PRIVATE algs Catch2::Catch2)
add_test(NAME testlibtest COMMAND testlib)
