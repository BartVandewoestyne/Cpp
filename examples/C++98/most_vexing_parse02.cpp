/**
 * Illustration of the most vexing parse, which is a specific form of syntactic
 * ambiguity resolution in the C++ programming language.
 *
 * References:
 *
 *   [1] http://www.reddit.com/r/cpp/comments/x3o9z/psa_the_most_vexing_parse/
 *   [2] http://stackoverflow.com/questions/1424510/most-vexing-parse-why-doesnt-a-a-work
 *   [3] http://www2.research.att.com/~bs/C++0xFAQ.html#uniform-init
 */
#include <iostream>
#include <typeinfo>

struct A {
};

struct B {
    B(A a) {}
};

int main() {
    B b(A());
    std::cout << typeid(b).name() << "\n";
    return 0;
}
