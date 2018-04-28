#include <iostream>
#include <range/v3/all.hpp>
#include <string>
#include <vector>

int main() {
  std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto vs = vi | ranges::view::remove_if([](int i){ return i % 2 == 1; })
               | ranges::view::transform([](int i){ return std::to_string(i); });
  return 0;
}
