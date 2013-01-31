#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;

    int v1 = 0, v2 = 0;

    std::cin >> v1 >> v2;

    // The code below is not legal.
    //std::cout << "The sum of " << v1;
    //          << " and " << v2;
    //          << " is " << v1 + v2 << std::endl;

    // Removing the semicolons at the end of the first two lines solves the
    // problem.
    std::cout << "The sum of " << v1
              << " and " << v2
              << " is " << v1 + v2 << std::endl;

    return 0;
}
