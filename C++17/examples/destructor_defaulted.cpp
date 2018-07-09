/*
 * Explicitly defaulting a class's destructor causes the compiler not to
 * implicitly define any move constructor at all.
 *
 * References:
 *
 *   [odwyer20180707] Defaulted destructor inhibits move
 *     https://quuxplusone.github.io/blog/2018/07/07/defaulted-destructor-inhibits-move/
 */

#include <cassert>
#include <memory>
#include <type_traits>

struct Okay {
    std::shared_ptr<int> p;
    Okay(std::shared_ptr<int> p) : p(p) {}
};
static_assert(std::is_copy_constructible_v<Okay>);
static_assert(std::is_move_constructible_v<Okay>);

struct Oops {
    std::shared_ptr<int> p;
    Oops(std::shared_ptr<int> p) : p(p) {}
    ~Oops() = default;
};
static_assert(std::is_copy_constructible_v<Oops>);
static_assert(std::is_move_constructible_v<Oops>);

int main() {
    Okay a = std::make_shared<int>(42);
    Okay b = std::move(a);
    assert(b.p && !a.p);
    Oops c = std::make_shared<int>(42);
    Oops d = std::move(c);
    assert(d.p && c.p);
}
