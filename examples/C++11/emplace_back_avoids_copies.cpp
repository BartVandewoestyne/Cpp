/*
 * Program to demonstrate how std::vector::emplace_back avoids extra copies.
 *
 * References:
 *
 *   [bendersky2014] Perfect forwarding and universal references in C++
 *     http://eli.thegreenplace.net/2014/perfect-forwarding-and-universal-references-in-c/
 *
 *   [wright2013totw65] Tip of the Week #65: Putting Things in their Place
 *     https://abseil.io/tips/65
 */

#include <iostream>
#include <vector>

class Foo {
public:
    Foo(int i, float f)
    { std::cout << "Foo(int, float)" << std::endl; }

    Foo(const Foo& other)
    { std::cout << "Foo(const Foo& other)" << std::endl; }

    Foo(Foo&& other)
    { std::cout << "Foo(Foo&& other)" << std::endl; }

    ~Foo()
    { std::cout << "~Foo()" << std::endl; }
};

int main()
{
    std::vector<Foo> v_pb;
    std::cout << "v.push_back(Foo(2, 3.14f))" << std::endl;
    v_pb.push_back(Foo(2, 3.14f));

    std::vector<Foo> v_eb;
    std::cout << "v.emplace_back(2, 3.14f)" << std::endl;
    v_eb.emplace_back(2, 3.14f);

    std::cout << "right before closing brace:" << std::endl;
}
