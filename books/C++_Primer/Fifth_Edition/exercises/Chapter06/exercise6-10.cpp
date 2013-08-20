#include <iostream>

void swapthem(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
  int x = 1;
  int y = 2;

  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;

  swapthem(&x, &y);

  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
}
