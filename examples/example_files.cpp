#include <blib/estd.hpp>
#include <blib/files.hpp>

int main() {
    auto f = bemii::read_file("../CMakeLists.txt");
    bemii::for_each(f, bemii::print<std::string>);

    return 0;
}
