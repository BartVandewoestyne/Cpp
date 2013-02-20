#include <iostream>

int main()
{
    // OK!
    int month = 9, day = 7;

    // Error: 'invalid digit "9" in octal constant'
    //int month = 09, day = 07;

    std::cout << "month = " << month
              << ", day = " << day << std::endl;
}
