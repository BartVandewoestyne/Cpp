/*
 * Key ideas:
 *
 *   * Class template parameter types can now be deduced according to
 *     arguments passed to the constructor.
 *
 *   * Partial class template argument deduction is not possible
 *
 * References:
 *
 *   [chen20220420] Class template argument deduction may be the new hotness, but we’ll always have maker functions
 *     https://devblogs.microsoft.com/oldnewthing/20220420-00/?p=106506
 *
 *   [orians20200716] Improving Readability With Class Template Argument Deduction - A.J. Orians [ C++ on Sea 2020 ]
 *     https://cpponsea.uk/2020/sessions/improving-readability-with-class-template-argument-deduction.html
 *
 *   [lavavej20181011] How to Use Class Template Argument Deduction
 *     https://blogs.msdn.microsoft.com/vcblog/2018/10/11/how-to-use-class-template-argument-deduction/
 *     https://devblogs.microsoft.com/cppblog/how-to-use-class-template-argument-deduction/
 *
 *   [orr201802XX] CTAD – What Is This New Acronym All About? (Overload Journal #143, Roger Orr)
 *     https://accu.org/index.php/journals/2465
 *
 *   [doumler2017] The new C++17 and why it's good for you - Timur Doumler, ADC 2017
 *     https://youtu.be/ky_eXBMcJK0?t=7m53s
 *     
 *   [yuan20170926] Class Template Argument Deduction: A New Abstraction
 *     https://youtu.be/4X8gXzi8bx8
 *
 *   [revzin2017XXXX] Uniform initialization isn’t
 *     https://medium.com/@barryrevzin/uniform-initialization-isnt-82533d3b9c11
 *
 *   [deane2017XXXX] C++17 Class Templates: Deduced or Not?
 *     http://www.elbeno.com/blog/?p=1450
 *
 *   [mertz2017XXXX] Modern C++ Features – Class Template Argument Deduction
 *     https://arne-mertz.de/2017/06/class-template-argument-deduction/
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 */

#include <complex>
#include <iostream>
#include <string>

template <typename T1, typename T2>
class D
{
  public:
    D(T1 x = T1(), T2 y = T2()) {}
};

template <typename T1, typename T2, typename T3 = T2>
class C
{
  public:
    C(T1 x = T1(), T2 y = T2(), T3 z = T3()) {}
};

int main()
{
    // OK, T1 and T2 are std::string
    D<std::string, std::string> d0;

    // OK, T1 and T2 are std::string
    D<std::string, std::string> d1("hi", "world");

    // OK since C++17, T1 is const char[3], T2 is const char[6]
    // TODO: check if types are not just const char* ???  See also comment
    // from Josuttis itself in his presentation...
    D d2("hi", "world");

    // OK since C++17, T1 is int, T2 is double
    D d3(22, 44.3);

    // Error: T1 and T2 undefined
    //D d4;
    
    // OK since C++17, deduces a std::complex<int>
    std::cout << std::complex(5, 3);

    // Error: args do not have the same type.
    //std::cout << std::complex(5, 3.3);

    // OK, T1, T2 are string, T2 is int
    C<std::string, std::string, int> c0;

    // OK, T1, T2 are string, T2 is int
    C<std::string, std::string, int> c1("hi", "guy", 42);

    // OK, T1 is int, T2 and T3 are strings
    C<int, std::string> c2(52, "my");

    // OK, T1, T2, T3 are strings
    C<std::string, std::string> c3("hi", "my", "guy");

    // Error: 42 is not a string
    //C<std::string, std::string> c4("hi", "my", 42);

    // Error: T1 and T2 undefined.
    //C c5;

    // Error: T2 undefined
    //C c6("hi");

    // OK since C++17, T1 is int, T2 and T3 are double
    C c7(22, 44.3);

    // OK since C++17, T1 is int, T2 is double, T3 is const char[3]
    C c8(22, 44.3, "hi");

    // OK since C++17, T1 is const char[3], T2 and T3 are const char[4]
    C c9("hi", "guy");

    // Error: only T1 explicitly defined
    //C<std::string> c10("hi", "my");

    // Error: neither T1 nor T2 explicitly defined
    //C<> c11(22, 44.3);

    // Error: neither T1 nor T2 explicitly defined
    //C<> c12(22, 44.3, 42);
}
