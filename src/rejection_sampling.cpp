#include <algorithm>
#include <boost/random.hpp>
#include <cmath>
#include <iterator>
#include <matplot/matplot.h>
#include <random>

const int N = 100000;

std::vector<std::pair<float, float>> unif_rect(int n, int a, int b, int c,
                                               int d) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<std::pair<float, float>> values(n);
  std::uniform_real_distribution<> disa(a, b);
  std::uniform_real_distribution<> disb(c, d);
  std::generate(values.begin(), values.end(),
                [&]() { return std::make_pair(disa(gen), disb(gen)); });
  return values;
}

std::vector<float> rejection_sample(std::function<float(float)> g,
                                    int sample_size, int a, int b, int c,
                                    int d) {
  /*
   * Rejection sampling algorithm
   */
  std::vector<std::pair<float, float>> xy = unif_rect(sample_size, a, b, c, d);

  for (int i = 0; i < sample_size; ++i) {
    std::pair<float, float> curr = xy[i];
    while (curr.second > g(curr.first)) {
      std::pair<float, float> gen = unif_rect(1, a, b, c, d)[0];
      xy[i] = gen;
      curr = xy[i];
    }
  }

  std::vector<float> x;
  std::transform(begin(xy), end(xy), std::back_inserter(x),
                 [](auto const &pair) { return pair.first; });
  return x;
}

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
