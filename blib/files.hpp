#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace bemii {

    std::vector<std::string> read_file(std::string from) {
        std::ifstream is{from};
        if (is.is_open()) {
            std::vector<std::string> _v;
            std::string line;
            while (std::getline(is, line)) {
                _v.push_back(line);
            }
            return _v;
        } else {
            std::cerr << "Warning: File didn't exist!";
            std::vector<std::string> _v{""};
            return _v;
        }
    };

} // namespace bemii
