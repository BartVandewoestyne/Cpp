/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 *
 * TODO:
 *   This example code was not yet compileable at the time I wrote it.  Test!
 */

#include <execution>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> str{"Only", "for", "testing", "purpose"};

    std::size_t result= std::transform_reduce(std::par,  // TODO: shouldn't this be std::execution::par?
    	str.begin(), str.end(),
    	0, [](std::size_t a, std::size_t b){ return a + b; },
    	[](std::string s){ return s.length(); });

    std::cout << result << std::endl; // 21
}
