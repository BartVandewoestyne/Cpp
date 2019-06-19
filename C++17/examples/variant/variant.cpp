/*
 * References:
 *
 *   [fahller20190613] Variant visitation variations
 *     https://youtu.be/ERHYJy5KxQo
 *
 *   [liber20190510] The Many Variants of std::variant
 *     https://youtu.be/JUxhwf7gYLg
 *
 *   [arias20180626] std::variant Doesn't Let Me Sleep
 *      https://pabloariasal.github.io/2018/06/26/std-variant/
 *
 *   [filipek20180604] Everything You Need to Know About std::variant from C++17
 *     https://www.bfilipek.com/2018/06/variant.html
 *
 *   [mertz20180509] Modern C++ Features – std::variant and std::visit
 *     https://arne-mertz.de/2018/05/modern-c-features-stdvariant-and-stdvisit/
 *
 *   [doumler2017] The new C++17 and why it's good for you (ADC'17)
 *     https://youtu.be/ky_eXBMcJK0?t=27m8s
 *
 *   [grimm2017unions] C++ Core Guidelines: Regeln fur Unions
 *     https://www.heise.de/developer/artikel/C-Core-Guidelines-Regeln-fuer-Unions-3893493.html
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 *     
 *   [bolton2016] Breaking Down the Current State of C++ 17
 *     http://insights.dice.com/2016/12/15/breaking-down-current-state-c-17/
 */

#include <variant>
#include <string>
 
int main()
{
    // v and w are two variants.  Both can have an int and a float value.
    // Their default value is 0.
    std::variant<int, float> v, w;

    v = 12;  // v contains int
    const auto i = std::get<int>(v);

    // Three possibilities to assign the variant v to w.
    w = std::get<int>(v);
    w = std::get<0>(v);  // same effect as the previous line
    w = v;               // same effect as the previous line
 
//    std::get<double>(v);  // error: no double in [int, float]
//    std::get<3>(v);       // error: valid index values are 0 and 1
 
    try {
      std::get<float>(w);  // w contains int, not float: will throw
    }
    catch (std::bad_variant_access&) {}
 
    std::variant<std::string> s("abc"); // converting constructor must be unambiguous
    s = "def";                          // converting assignment must be unambiguous
}
