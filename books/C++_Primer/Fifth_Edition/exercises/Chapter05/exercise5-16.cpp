#include <iostream>
#include <vector>

int main()
{
    int number = 0;
    std::vector<int> v = {1, 2, 3};

    // A) read values until end-of-file.
    while (std::cin >> number)
    {
        std::cout << number << std::endl;
    }

    // B) an index steps through a range of values in a collection.
    for (decltype(v.size()) i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }

    // A) rewritten using for-loop.
    // TODO

    // B) rewritten using while loop.
    decltype(v.size()) i = 0;
    while (i < v.size())
    {
        std::cout << v[i] << std::endl;
        ++i;
    }
}
