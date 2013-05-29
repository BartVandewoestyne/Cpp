#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myvector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    myvector.resize(5);

    for (const auto& element : myvector)
    {
        std::cout << element << std::endl;
    }
}
