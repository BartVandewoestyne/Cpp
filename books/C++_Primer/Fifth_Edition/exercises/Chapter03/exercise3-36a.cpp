#include <iostream>
#include <iterator>

int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {2, 3, 4, 5};

    int *pbeg1 = std::begin(arr1);
    int *pend1 = std::end(arr1);
    int *pbeg2 = std::begin(arr2);
    int *pend2 = std::end(arr2);

    if (pend1 - pbeg1 != pend2 - pbeg2)
    {
        std::cout << "Array lengths are not equal!" << std::endl;
    }
    else
    {
        while ( (pbeg1 != pend1) && (*pbeg1 == *pbeg2) )
        {
            ++pbeg1;
            ++pbeg2;
        }
        if (pbeg1 == pend1)
        {
            std::cout << "Arrays are equal!" << std::endl;
        }
        else
        {
            std::cout << "Arrays are NOT equal!" << std::endl;
        }
    }
}
