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
