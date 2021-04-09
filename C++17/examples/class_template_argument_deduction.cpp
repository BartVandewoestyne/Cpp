/*
 * References:
 *
 *   [orians20200716] Improving Readability With Class Template Argument Deduction - A.J. Orians [ C++ on Sea 2020 ]
 *     https://cpponsea.uk/2020/sessions/improving-readability-with-class-template-argument-deduction.html
 *
 *   [lavavej20181011] How to Use Class Template Argument Deduction
 *     https://blogs.msdn.microsoft.com/vcblog/2018/10/11/how-to-use-class-template-argument-deduction/
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
}
