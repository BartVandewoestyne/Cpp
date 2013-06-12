#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {3, 2, 1};

    // (a)
    std::cout << "(a):" << std::endl;
    std::cout << * vec.begin() << std::endl;        // Results in 3.
    std::cout << (* vec.begin()) << std::endl;      // Results in 3.

    // (b) -> dereference has higher precedence than add
    std::cout << "(b):" << std::endl;
    std::cout << * vec.begin() + 1 << std::endl;    // Results in 4.
    std::cout << * (vec.begin() + 1) << std::endl;  // Results in 2.
    std::cout << (* vec.begin()) + 1 << std::endl;  // Results in 4.
}
