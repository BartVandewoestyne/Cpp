/*
 * Key ideas:
 *
 *   - The addition of make_unique finally means we can tell people to 'never'
 *     use new rather than the previous tule to "'never' use new except when
 *     you make a unique_ptr".
 *
 *   - make_unique is safe for creating temporaries, whereas with explicit use
 *     of new you have to remember the rule about not using unnamed temporaries:
 *
 *       foo(make_unique<T>(), make_unique<U>());  // exception safe
 *
 *       foo(unique_ptr<T>(new T()), unique_ptr<U>(new U()));  // unsafe*
 *
 *       [*] It is expected that C++17 will include a rule change that means
 *           that this is no longer unsafe.  See C++ committee papers
 *           P0400R0 and P0145R3.
 *
 *   - make_unique does not require redundant type usage, e.g. compare
 *
 *       std::unique_ptr<LongTypeName> up(new LongTypeName(args))
 *
 *     with
 *
 *       auto up = std::make_unique<LongTypeName>(args)
 *
 * References:
 * 
 *   [cppreference] http://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
 *
 *   [sahar2016] Exploring std::unique_ptr.
 *     http://shaharmike.com/cpp/unique-ptr/ (haven't read this one yet)
 *
 *   [niting2016] Advantages of using make_unique over new operator [duplicate].
 *     https://stackoverflow.com/questions/37514509/advantages-of-using-make-unique-over-new-operator
 *
 *   [stackoverflow20140321] Differences between std::make_unique and std::unique_ptr.
 *     https://stackoverflow.com/questions/22571202/differences-between-stdmake-unique-and-stdunique-ptr-with-new
 */

#include <iostream>
#include <memory>

class Foo
{
public:
    Foo() { std::cout << "Foo()" << std::endl; }
    ~Foo() { std::cout << "~Foo()" << std::endl; }
};

int main()
{
    auto f = std::make_unique<Foo>();
}
