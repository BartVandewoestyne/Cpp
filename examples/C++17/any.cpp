/*
 * References:
 *
 *   [grimm2017cpplibrary2nd] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <any>
#include <iostream>
#include <string>
#include <vector>

struct MyClass{};

int main()
{
    std::vector<std::any> anyVec({true, 2017, std::string("test"), 3.14, MyClass()});

    std::cout << std::any_cast<bool>(anyVec[0]) << std::endl;  // true
    std::cout << std::any_cast<int>(anyVec[1]) << std::endl;  // 2017

    std::cout << anyVec[0].type().name() << std::endl;  // b
    std::cout << anyVec[1].type().name() << std::endl;  // i
}
