#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1 = {0, 1, 1, 2};
    std::vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

    auto minSize = std::min(v1.size(), v2.size());
    bool equal = true;
    for ( decltype(minSize) i = 0; i < minSize; ++i )
    {
        if (v1[i] != v2[i])
        {
            equal = false;
        }
    }

    std::cout << "Program returns " << equal << std::endl;
}
