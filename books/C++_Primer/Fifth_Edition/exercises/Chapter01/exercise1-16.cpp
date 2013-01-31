/*
 * On Windows, press CTRL+z to generate an end-of-file.
 * On Unix, press CTRL+d to generate an end-of-file.
 */

#include <iostream>

int main()
{
    int sum = 0, value = 0;

    while (std::cin >> value)
        sum += value;

    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
