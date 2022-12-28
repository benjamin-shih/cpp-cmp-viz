#include <tuple>
#include <vector>

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
std::tuple<double, double> accumulate_vector(const std::vector<double> &values);
