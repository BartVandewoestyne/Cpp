/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <array>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::array<int, 9> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << std::accumulate(arr.begin(), arr.end(), 0); // 45
    std::cout << std::accumulate(arr.begin(), arr.end(), 1,
        [](int a, int b){ return a*b; } ); // 362880

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> myVec;
    std::adjacent_difference(vec.begin(), vec.end(),
    	std::back_inserter(myVec), [](int a, int b){ return a*b; });
    for (const auto& v: myVec) std::cout << v << " "; // 1 2 6 12 20 30 42 56 72
    std::cout << std::inner_product(vec.begin(), vec.end(), arr.begin(), 0); // 285

    myVec= {};
    std::partial_sum(vec.begin(), vec.end(), std::back_inserter(myVec));
    for (const auto& v: myVec) std::cout << v << " "; // 1 3 6 10 15 21 28 36 45

    std::vector<int> myLongVec(10);
    std::iota(myLongVec.begin(), myLongVec.end(), 2000);
    for (const auto& v: myLongVec) std::cout << v << " ";
    	// 2000 2001 2002 2003 2004 2005 2006 2007 2008 2009
}
