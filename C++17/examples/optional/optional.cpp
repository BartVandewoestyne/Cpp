/*
 * Key ideas:
 *
 *   - The most common place to use std::optional is when you want to indicate
 *     there is no value, or something was not found in a return type or a
 *     parameter.
 *
 *   - With std::optional, there’s no way to know what was the reason why a
 *     value wasn’t computed.  It is therefore recommended to use optional<T> in
 *     situations where there is exactly one, clear (to all parties) reason for
 *     having no value of type T, and where the lack of value is as natural as
 *     having any regular value of T.
 *
 *   - If you also want to know the *reason* for why no error was returned, you
 *     might checkout C++23's std::expected.
 *
 *   - Any time you need a tool to express “value-or-not-value”, or “possibly
 *     an answer”, or “object with delayed initialization”, you should reach into
 *     your toolbox for std::optional. Using a vocabulary type for these cases
 *     raises the level of abstraction, making it easier for others to understand
 *     what your code is doing.
 *
 * References:
 *
 *   [chen20211004] Some lesser-known powers of std::optional
 *     https://devblogs.microsoft.com/oldnewthing/20211004-00/?p=105754
 *
 *   [carvalho20210919] std::optional and non-POD C++ types
 *     http://blog.felipe.rs/2021/09/19/std-optional-and-non-pod-types-in-cpp/
 *
 *   [boccara20210514] A Default Value to Dereference Null Pointers
 *     https://www.fluentcpp.com/2021/05/14/a-default-value-to-dereference-null-pointers/
 *
 *   [copperspice20190912] Any Optional
 *     https://youtu.be/6A3Y3YDTC-0
 *
 *   [carter20180904] std::optional: How, when, and why
 *     https://blogs.msdn.microsoft.com/vcblog/2018/09/04/stdoptional-how-when-and-why/
 *
 *   [filipek20180611] A Wall of Your std::optional Examples
 *     https://www.bfilipek.com/2018/06/optional-examples-wall.html
 *
 *   [mertz20180606] Modern C++ Features - std::optional
 *     https://arne-mertz.de/2018/06/modern-c-features-stdoptional/
 *
 *   [filipek20180521] Error Handling and std::optional
 *     https://www.bfilipek.com/2018/05/errors-and-optional.html
 *
 *   [filipek20180507] Using C++17 std::optional
 *     https://www.bfilipek.com/2018/05/using-optional.html
 *
 *   [filipek20180423] Refactoring with C++17 std::optional
 *     https://www.bfilipek.com/2018/04/refactoring-with-c17-stdoptional.html
 *
 *   [brand201802XX] Functional Error-Handling with Optional and Expected (Simon Brand, Overload #143)
 *     https://accu.org/index.php/journals/2462
 *
 *   [brand2017] Functional exceptionless error-handling with optional and expected
 *     https://blog.tartanllama.xyz/optional-expected/
 *
 *   [doumler2017] The new C++17 and why it's good for you (ADC'17)
 *     https://youtu.be/ky_eXBMcJK0?t=33m40s
 *
 *   [turner2017optional] C++ Weekly - Ep 87 - std::optional
 *     https://youtu.be/PiaZkNp_fIM
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=32m17s
 *
 *   [fertig2017overload] About the C++ Core Guidelines, Andreas Fertig, Overload 140, page 26.
 *     https://members.accu.org/index.php/journals/2402
 *
 *   [sutter2013factories] GotW #90: Factories
 *     https://herbsutter.com/2013/05/29/gotw-90-factories/
 *     https://herbsutter.com/2013/05/30/gotw-90-solution-factories/
 */

#include <iostream>
#include <optional>
#include <string>
 
// std::optional can be used as the return type of a factory that may fail.
std::optional<std::string> create(bool b)
{
    if (b)
    {
        return "Godzilla";
    }
    return {};
}
 
int main()
{
    std::cout << "create(false) returned "
              << create(false).value_or("empty") << '\n';

    std::cout << "create(true) returned "
              << create(true).value_or("empty") << '\n';
 

    // Optional-returning factory functions are usable as conditions of
    // while and if.

    if (auto str = create(true)) {
        std::cout << "create(true) returned " << *str << '\n';
    }
}
