/*
 * References:
 *
 *   [mestre20190710] Templated Runtime Polymorphism
 *     https://sebmestre.blogspot.com/2019/07/templated-runtime-polymorphism.html
 *   [fahller20190613] Variant visitation variations
 *     https://youtu.be/ERHYJy5KxQo
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <iostream>
#include <variant>
#include <vector>

int main()
{
    std::vector<std::variant<char, long, float, int, double, long long>>
        vecVariant = {5, '2', 5.4, 100ll, 2011l, 3.5f, 2017};

    for (const auto& v: vecVariant)
    {
        std::visit([](auto&& arg) { std::cout << arg << " "; }, v);
        // 5 2 5.4 100 2011 3.5 2017
    }

    // display each type
    for (const auto& v: vecVariant)
    {
        std::visit([](auto&& arg){std::cout << typeid(arg).name() << " ";}, v);
        // int char double __int64 long float int
    }

    // get the sum
    std::common_type<char, long, float, int, double, long long>::type res{};
    std::cout << typeid(res).name() << std::endl;  // double
    for (const auto& v: vecVariant)
    {
        std::visit([&res](auto&& arg) { res += arg; }, v);
    }
    std::cout << "res: " << res << std::endl;  // 4191.9

    // double each value
    for (auto& v: vecVariant)
    {
        std::visit([&res](auto&& arg){arg *= 2;}, v);
        std::visit([](auto&& arg){std::cout << arg << " ";}, v);
        // 10 d 10.8 200 4022 7 4034
    }
}
