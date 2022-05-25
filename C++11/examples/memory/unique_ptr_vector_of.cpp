/*
 * Self-written test program to see if we can copy vectors of std::unique_ptr.
 *
 * References:
 *
 *   [stackoverflow20171115] Why is move necessary with emplace_back in this example?
 *     https://stackoverflow.com/questions/47313833/why-is-move-necessary-with-emplace-back-in-this-example
 *
 *   [devlieghere20170417] Exposing Containers of Unique Pointers
 *     https://jonasdevlieghere.com/containers-of-unique-pointers/
 *
 *   [stackoverflow20150317] push_back or emplace_back with std::make_unique
 *     https://stackoverflow.com/questions/29089227/push-back-or-emplace-back-with-stdmake-unique
 *
 *   [stackoverflow20130403] Should I use C++11 emplace_back with pointers containters?
 *     https://stackoverflow.com/questions/15783342/should-i-use-c11-emplace-back-with-pointers-containters
 *
 *   [stackoverflow20130123] What is the correct usage of std::unique_ptr while pushing into std::vector
 *     https://stackoverflow.com/questions/14484183/what-is-the-correct-usage-of-stdunique-ptr-while-pushing-into-stdvector
 */

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

struct Foo {
    Foo() { std::cout << "Foo()" << std::endl; }
    ~Foo() { std::cout << "~Foo()" << std::endl; }
};

class Bar {
public:
    Bar() {
        std::unique_ptr<Foo> pf(new Foo());
        v.push_back(std::move(pf));
    }

    std::vector<std::unique_ptr<Foo>>& getV() { return v; }  // note that getV returns a reference

private:
    std::vector<std::unique_ptr<Foo>> v;
};

int main()
{
    /* Test 1: copy vector of unique_ptrs */

    {
        std::unique_ptr<Foo> pf(new Foo());

        std::vector<std::unique_ptr<Foo>> v_src;
        //v_src.push_back(pf);                     // error, as copy constructor does not exist for std::unique_ptr
        v_src.push_back(std::move(pf));            // needs std::move

        std::vector<std::unique_ptr<Foo>> v_dest;
        //v_dest = v_src;                          // error, as copy constructor does not exist for std::unique_ptr
        v_dest = std::move(v_src);                 // needs std::move
    }

    {
        Bar bar;
        auto& v_dest = bar.getV();  // note that we need to assign to reference here
    }
}
