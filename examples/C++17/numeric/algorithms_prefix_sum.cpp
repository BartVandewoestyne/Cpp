/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> resVec{1, 2, 3, 4, 5, 6, 7, 8};
    std::exclusive_scan(std::execution::par,
    	resVec.begin(), resVec.end(), resVec.begin(), 1,
    	[](int fir, int sec){ return fir * sec; });

    for (auto v: resVec) std::cout << v << " "; // 1 1 2 6 24 120 720 5040

    std::vector<int> resVec2{1, 2, 3, 4, 5, 6, 7, 8};

    std::inclusive_scan(std::execution::par,
    	resVec2.begin(), resVec2.end(), resVec2.begin(),
    	[](int fir, int sec){ return fir * sec; }, 1);

    for (auto v: resVec2) std::cout << v << " "; // 1 2 6 24 120 720 5040 40320

    std::vector<int> resVec3{1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> resVec4(resVec3.size());
    std::transform_exclusive_scan(std::execution::par,
    	resVec3.begin(), resVec3.end(),
    	resVec4.begin(), 0,
    	[](int fir, int sec){ return fir + sec; },
    	[](int arg){ return arg *= arg; });

    for (auto v: resVec4) std::cout << v << " "; // 0 1 5 14 30 55 91 140

    std::vector<std::string> strVec{"Only", "for", "testing", "purpose"};
    std::vector<int> resVec5(strVec.size());

    std::transform_inclusive_scan(std::execution::par,
    	strVec.begin(), strVec.end(),
    	resVec5.begin(), 0,
    	[](auto fir, auto sec){ return fir + sec; },
    	[](auto s){ return s.length(); });

    for (auto v: resVec5) std::cout << v << " "; // 4 7 14 21

    std::vector<std::string> strVec2{"Only", "for", "testing", "purpose"};

    std::string res = std::reduce(std::execution::par,
    	strVec2.begin() + 1, strVec2.end(), strVec2[0],
    	[](auto fir, auto sec){ return fir + ":" + sec; });

    std::cout << res; // Only:for:testing:purpose

    std::size_t res7 = std::transform_reduce(std::execution::par,
    	strVec2.begin(), strVec2.end(),
    	[](std::string s){ return s.length(); },
    	0, [](std::size_t a, std::size_t b){ return a + b; });

    std::cout << res7; // 21
}
