/*
 * Self-written test program to see if we can copy vectors of std::unique_ptr.
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
