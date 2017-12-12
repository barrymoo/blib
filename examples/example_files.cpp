#include <blib/estd.hpp>
#include <blib/files.hpp>
#include <functional>

template <typename T>
std::function<void(const T &)> print =
    [](const T &t) { std::cout << t << '\n'; };

int main() {
  auto f = bemii::read_file("../CMakeLists.txt");
  bemii::for_each(f, print<std::string>);
  
  return 0;
}
