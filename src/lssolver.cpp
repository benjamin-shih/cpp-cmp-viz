#include <Eigen/Dense>
#include <cpp_viz/lib.hpp>
#include <iostream>

void LinAlg::qr_decomp(Eigen::MatrixXf A, Eigen::VectorXf b) {
  /*
   * QR Decomposition solver for linear least square system
   */
  std::cout << A.colPivHouseholderQr().solve(b) << std::endl;
}
