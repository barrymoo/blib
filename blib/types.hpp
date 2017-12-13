#include <boost/format.hpp>
#include <boost/type_index.hpp>
#include <iostream>

namespace bemii {

    template<typename T>
    void show_type(const T &t) {
        using boost::format;
        using boost::typeindex::type_id_with_cvr;
        using std::cout;

        // show T
        cout << format("T = %s\n") % type_id_with_cvr<T>().pretty_name();

        // show t
        //cout << format("t = %s\n") % type_id_with_cvr<decltype(t)>().pretty_name();
    }

} // namespace bemii
