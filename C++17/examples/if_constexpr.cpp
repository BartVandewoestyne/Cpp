/*
 * Key ideas:
 *
 *   - if constexpr can simplify templates by avoiding special case to end the
 *     recursion.
 *
 *   - #ifdefs can be simplified using if constexpr.
 *
 * References:
 *
 *   [grimm20220214] constexpr if
 *     http://www.modernescpp.com/index.php/constespr-if
 *
 *   [mertz20191211] Constexpr FizzBuzz - An Exercise in Compile-Time Calculations
 *     https://arne-mertz.de/2019/12/constexpr-fizzbuzz/
 *
 *   [filipek20180312] Simplify code with 'if constexpr' in C++17
 *     http://www.bfilipek.com/2018/03/ifconstexpr.html
 *
 *   [weller20180222] How if constexpr simplifies your code in C++17
 *     https://www.meetingcpp.com/blog/items/How-if-constexpr-simplifies-your-code-in-Cpp17.html
 *
 *   [doumler2017] Timur Doumler - The new C++17 and why it's good for you (ADC2017)
 *     https://youtu.be/ky_eXBMcJK0?t=12m58s
 *
 *   [groarke2017] Simplifying Compile-Time Options With if constexpr
 *     https://philippegroarke.com/blog/2017/11/20/simplifying-compile-time-options-with-if-constexpr/

 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 *
 *   [brand20161212] Simplifying templates and #ifdefs with if constexpr
 *     https://tartanllama.github.io/c++/2016/12/12/if-constexpr/
 *
 *   [turner20160708] C++ Weekly Special Edition - Using C++17's constexpr if
 *     https://youtu.be/_Ny6Qbm_uMI
 *
 *   [turner20160705] C++ Weekly - Ep 18 C++17's constexpr if
 *     https://youtu.be/qHgM5UdzPQU
 */

#include <iostream>

// C++11 version

//void print()
//{}
//
//template<typename T, typename... Types>
//void print(const T& firstArg, const Types&... args)
//{
//    std::cout << firstArg << std::endl;
//    print(args...);
//}


// C++17 version with if constexpr

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    if constexpr(sizeof...(args) > 0) {
        print(args...);
    }
}

int main()
{
    print(42, "hello", 2.3, 'a');
}
