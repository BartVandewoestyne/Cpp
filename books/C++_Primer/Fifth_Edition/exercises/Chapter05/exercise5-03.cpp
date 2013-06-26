#include <iostream>

int main()
{
    int sum = 0, val = 1;

    // In my opinion, this is less readable.
    while (val <= 10 && (sum += val, ++val));

    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    return 0;
}
