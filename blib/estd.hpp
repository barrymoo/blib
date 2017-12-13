#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <iostream>

namespace bemii {

    template<typename A>
    std::vector<A> sort(std::vector<A> &a) {
        std::vector<A> _a(a.size());
        std::partial_sort_copy(a.begin(), a.end(), _a.begin(), _a.end());
        return _a;
    };

    template<typename T>
    void sort_inplace(std::vector<T> &t) {
        std::sort(t.begin(), t.end());
    };

    template<typename A, typename B>
    std::vector<B> map(const std::vector<A> &a, std::function<B(const A &)> f) {
        std::vector<B> b;
        std::transform(a.begin(), a.end(), std::back_inserter(b), f);
        return b;
    };

    template<typename T>
    T reduce(const std::vector<T> &t, const T &accum,
             std::function<T(const T &, const T &)> f) {
        return std::accumulate(t.begin(), t.end(), accum, f);
    };

    template<typename A, typename B>
    B map_reduce(const std::vector<A> &a, const B &accum,
                 std::function<B(const A &)> f,
                 std::function<B(const B &, const B &)> g) {
        return reduce<B>(map<A, B>(a, f), accum, g);
    };

    template<typename T, typename Function>
    Function for_each(const std::vector<T> &t, Function f) {
        std::for_each(t.begin(), t.end(), f);
    }

} // namespace bemii
