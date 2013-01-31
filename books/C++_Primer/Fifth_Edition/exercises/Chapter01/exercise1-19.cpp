#include <iostream>

int main()
{
    std::cout << "Enter two integers:" << std::endl;

    int i1 = 0, i2 = 0;
    std::cin >> i1 >> i2;

    // Swap i1 and i2 if i2 is the smallest one.
    if (i2 < i1 ) {
        int temp = i1;
        i1 = i2;
        i2 = temp;
    }

    int val = i1;
    while (val <= i2) {
        std::cout << val << std::endl;
        val++;
    }

    return 0;
}
