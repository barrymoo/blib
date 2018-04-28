#include <algorithm>
#include <blib/files.hpp>
#include <blib/string_funcs.hpp>
#include <iostream>
#include <string>

int main() {
  std::string s{"Split on a word"};

  std::cout << "Simple tokenize on whitespace\n";
  auto a = bemii::tokenize(s);
  for (auto const &i: a) {
    std::cout << "'" << i << "' ";
  }
  std::cout << '\n';

  std::cout << "Tokenize on character\n";
  auto b = bemii::tokenize(s, 'o');
  for (auto const &i: b) {
    std::cout << "'" << i << "' ";
  }
  std::cout << '\n';

  std::cout << "Tokenize on string\n";
  auto c = bemii::tokenize(s, "it");
  for (auto const &i: c) {
    std::cout << "'" << i << "' ";
  }
  std::cout << '\n';

  std::string t{"hello,world,from,csv,string"};
  std::cout << "CSV Example\n";
  auto d = bemii::tokenize(t, ',');
  for (auto const &i: d) {
    std::cout << "'" << i << "' ";
  }
  std::cout << '\n';

  std::cout << "Empty String\n";
  auto e = bemii::tokenize("hello");

  std::cout << "Read from file, vector of vectors\n";
  auto vs = bemii::read_file("../CMakeLists.txt");
  // Tokenize each line
  std::vector<std::vector<std::string>> vss;
  vss.reserve(vs.size());
  for (auto const &i: vs) {
    vss.emplace_back(bemii::tokenize(i, "ka"));
  }

  // Print out result
  for (auto const &i: vss) {
    for (auto const &j: i) {
      std::cout << "'" << j << "' ";
    }
    std::cout << "\n";
  }
  return 0;
}
