/*
 * References:
 *
 *   [kumar20201123] std::any - comparison with void* and motivating examples
 *     https://www.nextptr.com/tutorial/ta1571648512/stdany-comparison-with-void-and-motivating-examples
 *
 *   [oopscene20201030] C++17: std::any
 *     https://oopscenities.net/2020/10/30/cpp17_std_any/
 *
 *   [filipek20180618] Everything You Need to Know About std::any from C++17
 *     https://www.bfilipek.com/2018/06/any.html
 *
 *   [Z01dbrg20171220] Why was std::any added to C++17?
 *     https://www.reddit.com/r/cpp/comments/7l3i19/why_was_stdany_added_to_c17/
 *
 *   [doumler2017] The new C++17 and why it's good for you (ADC'17)
 *     https://youtu.be/ky_eXBMcJK0?t=32m40s
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
    const std::vector<std::any> anyVec{true, 2017, std::string("test"), 3.14, MyClass()};

    std::cout << std::any_cast<bool>(anyVec[0]) << std::endl;  // true
    std::cout << std::any_cast<int>(anyVec[1]) << std::endl;  // 2017

    std::cout << anyVec[0].type().name() << std::endl;  // b
    std::cout << anyVec[1].type().name() << std::endl;  // i
}
