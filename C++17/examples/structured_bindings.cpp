/*
 * Key ideas:
 *
 *   - Structured bindings can be used for creating *new* variables to hold the result.
 *     If you want to assign the result to *existing* variables, then you can use the old standby std::tie.
 *   - auto can have the usual qualifiers & and const.
 *   
 * References:
 *
 *   [chen20200925] Structured binding may be the new hotness, but we’ll always have std::tie
 *     https://devblogs.microsoft.com/oldnewthing/20200925-00/?p=104297
 *
 *   [khizbullin20200924] C++17 structured bindings for more safe, functional code
 *     https://itnext.io/c-17-structured-bindings-for-more-safe-functional-code-c0c5b4d31b0d
 *
 *   [boccara20180619] 3 Simple C++17 Features That Will Make Your Code Simpler
 *     https://www.fluentcpp.com/2018/06/19/3-simple-c17-features-that-will-make-your-code-simpler/
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 *
 *   [doumler2017] The new C++17 and why it's good for you - Timur Doumler, ADC 2017
 *     https://youtu.be/ky_eXBMcJK0?t=4m59s
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=34m15s
 *
 *   [1] http://insights.dice.com/2016/12/15/breaking-down-current-state-c-17/
 *
 *   [2] https://skebanga.github.io/structured-bindings/
 *
 *   [3] http://www.nuonsoft.com/blog/2017/07/26/c17-structured-bindings/
 */

#include <iostream>
#include <map>
#include <string>
#include <tuple>

struct MyStruct {
  int i;
  double d;
};

MyStruct foo() { return MyStruct{1, 2.0}; }

std::tuple<char, float, std::string> g() {
    return make_tuple('x', 5.0, std::string("bar"));
}

int main()
{
    // u, v have types int, double and are initialized by members of the
    // object returned by foo().
    auto [u, v] = foo();

    // a, b, c have types char, float std::string initialized by values of
    // returned tuple.
    auto [a, b, c] = g();

    // x and y are ints initialized by the elements of arr.
    int arr[] = {47, 11};
    auto [x, y] = arr;

    // Iterating over a map using structured bindings:
    std::map<int, int> m;
    for (const auto& [key, value] : m)
    {
        std::cout << key << std::endl;
        std::cout << value << std::endl;
    }

}
