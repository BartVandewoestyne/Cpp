#include <iostream>

int main()
{
  std::cout << "Enter two numbers: ";
  int a, b;
  std::cin >> a >> b;

  if (a > b)
  {
    std::cout << a << " is larger than " << b << std::endl;
  } else {
    std::cout << b << " is larger than " << a << std::endl;
  }
}
