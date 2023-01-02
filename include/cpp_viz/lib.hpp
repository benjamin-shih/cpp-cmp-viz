#include <Eigen/Dense>
#include <Eigen/SVD>
#include <iostream>
#include <tuple>
#include <vector>

template <typename Derived>
void print_size(const Eigen::EigenBase<Derived> &b) {
  std::cout << "size (rows, cols): " << b.size() << " (" << b.rows() << ", "
            << b.cols() << ")" << std::endl;
}

template <typename M, typename V>
Eigen::MatrixXf regress(const Eigen::MatrixBase<M> &X,
                        const Eigen::MatrixBase<V> &points) {
  // Solve OLS with SVD
  Eigen::JacobiSVD<Eigen::MatrixXf> svd;
  svd.compute(X, Eigen::ComputeThinV | Eigen::ComputeThinU);
  return svd.solve(points);
}

class RejectionSample {
public:
  RejectionSample() {}
  std::vector<float> res;
  std::vector<std::pair<float, float>> unif_rect(int n, int a, int b, int c,
                                                 int d);

  std::vector<float> rejection_sample(std::function<float(float)> g,
                                      int sample_size, int a, int b, int c,
                                      int d);
};

class LinAlg {
public:
  LinAlg() {}
  void qr_decomp(Eigen::MatrixXf A, Eigen::VectorXf b);
};

std::tuple<double, double> accumulate_vector(const std::vector<double> &values);
