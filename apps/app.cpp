#include <cpp_viz/lib.hpp>
#include <matplot/matplot.h>

const int N = 100000;

int main() {
  auto g = [](auto x) {
    return ((x > -1 && x < 0) || (x > 1 / 2 && x < 1))
               ? pow(sin(10 * x), 2) * abs(pow(x, 3) + 2 * x - 3)
               : 0;
  };
  std::vector<float> res = rejection_sample(g, N, -1, 1, 0, 10);
  auto h = matplot::hist(res);
  matplot::show();
  return 0;
}
