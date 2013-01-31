#include <iostream>

int main()
{
    std::cout << "Enter two integers:" << std::endl;

    int i1 = 0, i2 = 0;
    std::cin >> i1 >> i2;

    int val = i1;
    while (val <= i2) {
        std::cout << val << std::endl;
        val++;
    }

    return 0;
}
