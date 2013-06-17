#include <iostream>

int main()
{
    constexpr int size = 5;
    int ia[size] = {1, 2, 3, 4, 5};
    for (int *ptr = ia, ix = 0;
         ix != size && ptr != ia + size;
         ++ix, ++ptr)
    {
        // ix will run through the indices 0..4.
        std::cout << "ix = " << ix << std::endl;

        // *ptr will run through all the values in the array.
        std::cout << "*ptr = " << *ptr << std::endl << std::endl;
    }
}
