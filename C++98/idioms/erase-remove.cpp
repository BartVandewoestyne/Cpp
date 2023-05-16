/**
 * Program to illustrate the Erase-Remove idiom.  This idiom is used if you
 * have a vector and you want to remove certain elements from it for which a
 * certain predicate is true.  E.g. you want to remove all odd elements or so.
 *
 * Note that in C++20, there is std::erase and std::erase_if so this idiom is
 * no longer necessary.
 *
 * References:
 *
 *   [1] http://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
 *
 *   [boccara20180914] How to Remove Elements from a Sequence Container in C++
 *     https://www.fluentcpp.com/2018/09/14/how-to-remove-elements-from-a-sequence-container/
 *
 *   [2] Scott Meyers Effective STL book
 *
 *   [3] C9 lectures on the STL by Stephan T Lavavej, part 2 of N (around 40:00)
 *
 *   [grimm2022XXXX] Back to Basics: Standard Library Containers in Cpp - Rainer Grimm - CppCon 2022
 *     https://youtu.be/ZMUKa2kWtTk?t=483
 */

#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin();
         it != vec.end();
	 ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v;

    for (unsigned int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }
    print(v);

    // Use the Erase-Remove idiom to remove all elements that are 5.
    v.erase( std::remove( v.begin(), v.end(), 5), v.end() );
    print(v);
}
