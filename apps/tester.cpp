/*
 * Testing file for written functions
 */

#include <Eigen/Dense>
#include <cpp_viz/lib.hpp>
#include <cpp_viz/tempreg.hpp>

int main() {
  Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 2);
  Eigen::VectorXf B = Eigen::VectorXf::Random(3);

  const Eigen::MatrixXf X{{0, 0}, {1, 1}, {2, 2}};
  const Eigen::Vector3f y(3, 3, 3);

  std::cout << regress(X, y) << std::endl;
  print_size(X);

  LinAlg la;
  la.qr_decomp(A, B);
}
