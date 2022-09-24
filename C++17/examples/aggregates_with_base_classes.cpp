/* References:
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 */

#include <cstdint>

struct CType  // existing C type
{
    uint32_t value;
};

struct Derived : CType  // C++ type that extends C type
{
    int status;
    void f();
};

int main()
{
    Derived d1{{42}, 1};  // OK since C++17, initializes d.value and d.status
    Derived d2{{}, 1};  // OK since C++17, d.value is value initialized
    Derived d3{};  // Error since C++17 (but expected to compile for a while
                   // according to Josuttis)
}
