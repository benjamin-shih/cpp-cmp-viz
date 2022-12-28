#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <random>

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

namespace ba = boost::accumulators;

std::tuple<double, double>
accumulate_vector(const std::vector<double> &values) {

  ba::accumulator_set<double, ba::stats<ba::tag::mean, ba::tag::moment<2>>> acc;

  std::for_each(std::begin(values), std::end(values), std::ref(acc));

  return {ba::mean(acc), ba::moment<2>(acc)};
}
