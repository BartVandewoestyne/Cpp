#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    int arr[] = {1, 2, 3};
    std::vector<int> v(std::begin(arr), std::end(arr));

    for (auto e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
