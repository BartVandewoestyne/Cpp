#include <iostream>

int main()
{
    bool someValue = true;
    const int INITIAL_X = 2;
    const int INITIAL_Y = 3;

    int x = INITIAL_X;
    int y = INITIAL_Y;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    someValue ? ++x, ++y : --x, --y;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    x = INITIAL_X;
    y = INITIAL_Y;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    (someValue ? ++x, ++y : --x), --y;
    std::cout << "x = " << x << ", y = " << y << std::endl;
}
