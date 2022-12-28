#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <cpp_viz/lib.hpp>

TEST_CASE("Quick check", "[main]") {
  std::vector<double> values{1, 2., 3.};
  auto [mean, moment] = accumulate_vector(values);

  REQUIRE(moment == Approx(4.666666));
}

TEST_CASE("Check 2", "[main]") {
  std::vector<double> values{1, 2., 3.};
  auto [mean, moment] = accumulate_vector(values);

  REQUIRE(moment == Approx(4.666666));
}
