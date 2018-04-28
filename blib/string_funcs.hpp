#include <string>
#include <sstream>
#include <vector>

namespace bemii {

  std::vector<std::string> tokenize(std::string const s) {
    std::istringstream iss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(iss, item, ' ')) {
      if (item.length() != 0) tokens.emplace_back(item);
    }
    return tokens;
  }

  std::vector<std::string> tokenize(std::string const s, char const c) {
    std::istringstream iss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(iss, item, c)) {
      if (item.length() != 0) tokens.emplace_back(item);
    }
    return tokens;
  }

  std::vector<std::string> tokenize(std::string const s, std::string const d) {
    std::vector<std::string> tokens;
    auto i = 0;
    auto pos = s.find(d);
    while (pos != std::string::npos) {
      tokens.push_back(s.substr(i, pos - i));
      i = ++pos + d.length() - 1;
      pos = s.find(d, pos);
    }
    if (pos == std::string::npos) {
      std::string subs{s.substr(i, s.length())};
      if (subs.length() != 0) tokens.emplace_back(subs);
    }
    return tokens;
  }

} // namespace bemii
