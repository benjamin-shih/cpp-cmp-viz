#include <Eigen/Dense>
#include <mlpack.hpp>
#include <tuple>
#include <vector>

void regress(arma::mat data, arma::vec responses, arma::mat points,
             arma::rowvec predictions);

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
