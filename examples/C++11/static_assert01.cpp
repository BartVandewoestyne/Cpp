/**
 * References:
 *
 *   [bock20160116] How to test static_assert? - Roland Bock - Meeting C++ 2016
 *     https://youtu.be/zxDzMjfsgjg
 *
 *   [1] http://j.mp/cpp11ref
 */

#include <cstdint>
using namespace std;

template<class T>
void f(T v) {
    static_assert( sizeof(v) == 4, "v must have size of 4 bytes" );
    // do something with v
}

void g() {
    int64_t v; // 8 bytes
    f(v);
}
