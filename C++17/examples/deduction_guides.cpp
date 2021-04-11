/*
 * Deduction guides are a way to tell the compiler how to deduce class
 * templates when using a constructor.
 *
 * References:
 *
 *   [raggi20180717] How to Construct C++ Objects Without Making Copies
 *     https://www.fluentcpp.com/2018/07/17/how-to-construct-c-objects-without-making-copies/
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 */

#include <memory>

// deduction guide: maps shared pointer initialization to shared pointer type.
namespace std {
    template<typename Y> shared_ptr(Y*) -> shared_ptr<Y>;
}

int main()
{
    // OK
    std::shared_ptr<int> sp(new int(42));

    // Error without deduction guide (can't deduce type T from type Y)
    // OK with deduction guide
    std::shared_ptr sp2(new int(42));
}
