#include <iostream>

int main()
{
  int i = 1;

  std::cout << "i = " << i << std::endl;

  // The fastest way to change i from 2 to 1 or
  // from 1 to 2 ?
  i = 3 - i;

  std::cout << "i = " << i << std::endl;

}
