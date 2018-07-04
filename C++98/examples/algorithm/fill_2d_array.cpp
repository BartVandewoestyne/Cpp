#include <algorithm>
#include <iostream>

int main()
{
    int a[2][3];

    // Method 1
    std::fill(a[0], a[0] + 2*3, 999);

    // Method 2
    //std::fill_n(a[0], 2*3, 999);

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
