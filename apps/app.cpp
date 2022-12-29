#include <Eigen/Dense>
#include <cpp_viz/lib.hpp>
#include <functional>
#include <matplot/matplot.h>
/**
 * C++ only calling and running for rejection sampling class:
 * computation and resulting visuals are all in C++. Runs much
 * faster than viz.py by sacrifices visuals.
 *
 * Last edited: 12.27.22
 */
const int N = 100000;

void run_rej_samp(std::function<float(float)> g, int N, int a, int b, int c,
                  int d) {
  auto rej = RejectionSample();
  std::vector<float> res = rej.rejection_sample(g, N, a, b, c, d);
  auto h = matplot::hist(res);
  matplot::show();
}

int main() {
  auto g = [](auto x) {
    return ((x > -1 && x < 0) || (x > 1 / 2 && x < 1))
               ? pow(sin(10 * x), 2) * abs(pow(x, 3) + 2 * x - 3)
               : 0;
  };
  int a = -1, b = 1, c = 0, d = 10;
  run_rej_samp(g, N, a, b, c, d);

  Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 2);
  Eigen::VectorXf B = Eigen::VectorXf::Random(3);
  LinAlg la;
  la.qr_decomp(A, B);
  return 0;
}
