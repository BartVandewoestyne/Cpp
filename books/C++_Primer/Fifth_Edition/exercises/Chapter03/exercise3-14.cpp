#include <iostream>
#include <vector>

int main()
{
    const int MAX_NB_VALUES = 3;

    int number;

    std::vector<int> v;
     
    for (int i = 0; i != MAX_NB_VALUES; ++i)
    {
        std::cin >> number;
        v.push_back(number);
    }

    for (const auto& element : v)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
