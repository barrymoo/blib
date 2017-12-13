#include <blib/estd.hpp>

int main() {
    std::vector<int> a{3, 1, 2};

    // Helper Functions
    auto sum = [](const auto &x, const auto &y) { return x + y; };
    auto add_double = [](const auto &x) { return x + 1.5; };

    // Out of Place Sort
    auto b = bemii::sort(a);
    bemii::for_each(b, bemii::print<int>);
    std::cout << "\n";

    // Map Example
    auto c = bemii::map<int, double>(a, add_double);
    bemii::for_each(c, bemii::print<double>);
    std::cout << "\n";

    // MapReduce Working?
    auto d = bemii::map_reduce<int, double>(a, 0.0, add_double, sum);
    std::cout << d << "\n\n";

    // Reduce Working?
    auto e = bemii::reduce<int>(a, 0, sum);
    std::cout << e << "\n\n";

    return 0;
}
