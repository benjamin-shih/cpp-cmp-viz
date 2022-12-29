add_executable(app app.cpp)
target_compile_features(app PRIVATE cxx_std_11)
target_link_libraries(app PRIVATE algs Matplot++::matplot Eigen3::Eigen)
