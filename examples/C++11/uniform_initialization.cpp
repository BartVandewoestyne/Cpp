/**
 * References:
 *
 *   [1] http://www.reddit.com/r/cpp/comments/x3o9z/psa_the_most_vexing_parse/
 *   [2] http://en.wikipedia.org/wiki/C%2B%2B11#Uniform_initialization
 */
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v1(100, 0);
    std::cout << v1.size() << "\n";

    std::vector<int> v2{100, 0};
    std::cout << v2.size() << "\n";
    return 0;
}
