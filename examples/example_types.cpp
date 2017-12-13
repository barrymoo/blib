#include <blib/estd.hpp>
#include <blib/types.hpp>

int main() {
    std::vector<int> a{1, 2, 3};
    auto print = [](const auto &a){ std::cout << a << '\n'; };

    bemii::show_type(a);
    bemii::show_type(print);

    return 0;
}
