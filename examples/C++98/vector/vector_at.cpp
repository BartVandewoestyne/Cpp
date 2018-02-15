/*
 * References:
 *
 *   [shibli20130518] Vector going out of bounds without giving error
 *     https://stackoverflow.com/questions/16620222/vector-going-out-of-bounds-without-giving-error
 *
 *   [cppreference] std::vector::at
 *     http://en.cppreference.com/w/cpp/container/vector/at
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // Undefined behavior since vector indices start at 0.
    std::cout << v[3]  << std::endl;

    // This should throw and std::out_of_range exception.
    // TODO: check that it does...
    std::cout << v.at(3) << std::endl;
}
