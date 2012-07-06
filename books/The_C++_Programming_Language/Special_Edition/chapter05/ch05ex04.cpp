#include <iostream>

void swapWithPointers(int* p1, int* p2)
{
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}


void swapWithReferences(int& v1, int& v2)
{
  int tmp = v1;
  v1 = v2;
  v2 = tmp;
}


int main ()
{
  int x = 1;
  int y = 2;

  std::cout << "x = " << x << ", y = " << y << std::endl;
  swapWithPointers(&x, &y);
  std::cout << "x = " << x << ", y = " << y << std::endl;
  swapWithReferences(x, y);
  std::cout << "x = " << x << ", y = " << y << std::endl;
}
