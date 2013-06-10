#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3};

    const auto NB_ELEMENTS = v.size();
    int arr[NB_ELEMENTS];

    for (decltype(v.size()) i = 0; i < NB_ELEMENTS; ++i)
    {
        arr[i] = v[i];
    }

    for (decltype(v.size()) i = 0; i < NB_ELEMENTS; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
