/*
 * Key ideas:
 *
 * - Deduction guides are a way to tell the compiler how to deduce class
 *   templates when using a constructor.
 *
 * - Deduction guides can be explicit.
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
#include <set>
#include <string>
#include <vector>

// deduction guide: maps shared pointer initialization to shared pointer type.
namespace std {
    template<typename Y> shared_ptr(Y*) -> shared_ptr<Y>;
}

template <typename T>
struct S
{
    T val;
};

// Deduction guides:

// map S with string literals to S<std::string>
S(char const*) -> S<std::string>;

// map S with string literals to S<std::string> (not for implicit construction)
//explicit S(char const*) -> S<std::string>;

int main()
{
    // OK
    std::shared_ptr<int> sp(new int(42));

    // Error without deduction guide (can't deduce type T from type Y)
    // OK with deduction guide
    std::shared_ptr sp2(new int(42));

    // Error.
    //std::shared_ptr sp(new int[10]);
    

    // map vector initialization with iterators to vector iterator's element
    // type using the following deduction guide from the C++17 standard:
    //namespace std {
    //    template<typename Iterator> vector(Iterator, Iterator)
    //      -> vector<typename iterator_traits<Iterator>::value_type>;
    //}
    std::set<double> s;
    std::vector(s.begin(), s.end());  // deduces std::vector<double>

    // Also note that deduction guides...
    //   ... must not be templates
    //   ... must not call a constructor (e.g. also for aggregates)
    S s2{"hello"};  // same as S<std::string> s2("hello");

    S s3 = "hello";  // Error, both with explicit and non-explicit
                     // deduction guide??? (TODO: this does not match with
                     // Josuttis' slides... check why
}
