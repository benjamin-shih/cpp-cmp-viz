#include <iostream>
#include <string>
#include <vector>

int sum_integers(const std::vector<int> &integers) {
  auto sum = 0;
  /*
  for (auto i : integers) {
    sum += i;
  }
  */
  return sum;
}

int main(int argc, char *argv[]) {

  std::vector<int> integers;
  for (auto i = 1; i < argc; i++) {
    integers.push_back(std::stoi(argv[i]));
  }
  auto sum = sum_integers(integers);

  std::cout << sum << std::endl;
}
