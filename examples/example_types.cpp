#include <blib/types.hpp>
#include <functional>

template <typename T>
std::function<void(const T &)> print =
    [](const T &t) { std::cout << t << '\n'; };

int main() {
  bemii::show_type(print<int>);

  return 0;
}
