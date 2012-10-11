#include <iostream>

int main()
{
  int p = 1;
  for (int i=1; i < 10; ++i) {
    p *= i;
  }
  std::cout << "p = " << p << std::endl;
}
