/**
 * References:
 *
 *   [wikipedia] http://en.wikipedia.org/wiki/C%2B%2B11#Uniform_initialization
 *
 *   [odwyer20190218] The Knightmare of Initialization in C++
 *     https://quuxplusone.github.io/blog/2019/02/18/knightmare-of-initialization/
 *
 *   [revzin2017] Uniform initialization isn’t
 *     https://medium.com/@barryrevzin/uniform-initialization-isnt-82533d3b9c11
 *
 *   [reddit20120725] PSA: The Most Vexing Parse
 *     http://www.reddit.com/r/cpp/comments/x3o9z/psa_the_most_vexing_parse/
 */

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v1(100, 0);
    std::cout << v1.size() << "\n";

    std::vector<int> v2{100, 0};
    std::cout << v2.size() << "\n";

    return 0;
}
