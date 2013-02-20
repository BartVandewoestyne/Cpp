#include <iostream>

int main()
{
    // Method 1:
    std::cout << '\62' << '\115' << '\n';

    // Method 2:
    std::cout << "\62\115\n";

    std::cout << '\62' << '\011' << '\115' << '\n';
}
