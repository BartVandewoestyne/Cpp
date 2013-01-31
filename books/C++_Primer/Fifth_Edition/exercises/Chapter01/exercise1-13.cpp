#include <iostream>

int main()
{
    // Exercise 1.9 with for-loop.
    int sum = 0;
    for (int i=50; i<=100; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl;

    // Exercise 1.10 with for-loop.
    for (int i = 10; i >= 0; --i) {
        std::cout << i << std::endl;
    }

    // Exercise 1.11 with for-loop.
    std::cout << "Please enter two integers:" << std::endl;
    int v1=0, v2=0;
    std::cin >> v1 >> v2;
    for (int i=v1; i<=v2; i++) {
        std::cout << i << std::endl;
    }
}
