#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int number = 0;
    while (cin >> number && number != 42)
    {
        std::cout << "number = " << number << std::endl;
    }
    std::cout << "END" << std::endl;
}
