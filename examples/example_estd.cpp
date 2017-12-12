#include <blib/estd.hpp>
#include <iostream>
#include <functional>

template <typename T>
std::function<void(const T &)> print =
    [](const T &t) { std::cout << t << '\n'; };

int main() {
  std::vector<int> a{3, 1, 2};

  // Helper Functions
  auto sum = [](const auto &x, const auto &y) { return x + y; };
  auto add_double = [](const auto &x) { return x + 1.5; };

  // Sort Working?
  auto e = bemii::sort<int>(a);
  bemii::for_each(e, print<int>);
  std::cout << "\n";

  // Map Working?
  auto b = bemii::map<int, double>(a, add_double);
  bemii::for_each(b, print<double>);
  std::cout << "\n";

  // MapReduce Working?
  auto c = bemii::map_reduce<int, double>(a, 0, add_double, sum);
  std::cout << c << "\n\n";

  // Reduce Working?
  auto d = bemii::reduce<int>(a, 0, sum);
  std::cout << d << "\n\n";

  return 0;
}
