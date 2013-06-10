#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = {1, 2, 3, 4, 5};

    if (v1 == v2)
    {
        std::cout << "Vectors are equal" << std::endl;
    }
    else
    {
        std::cout << "Vectors are not equal" << std::endl;
    }
}
