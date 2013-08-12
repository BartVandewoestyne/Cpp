#include <iostream>

int abs_val(int x)
{
    if (x < 0)
      return -x;
    else
      return x;
}

int main()
{
    int x = 5;
    int y = -3;
    std::cout << "abs(" << x << ") is " << abs_val(x) << std::endl;
    std::cout << "abs(" << y << ") is " << abs_val(y) << std::endl;
}
