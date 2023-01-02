add_executable(run_rej_samp rejsamp_cpp.cpp)
target_compile_features(run_rej_samp PRIVATE cxx_std_11)
target_link_libraries(run_rej_samp PRIVATE algs Matplot++::matplot)

add_executable(runner tester.cpp)
target_compile_features(runner PRIVATE cxx_std_11)
target_link_libraries(runner PRIVATE algs Eigen3::Eigen)
