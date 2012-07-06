#include <iostream>
#include <cstring>

int main ()
{
  char str[] = "a short string";

  // This returns 15, because sizeof returns the size of the character array,
  // including the terminating 0.
  std::cout << "size of the array str = " << sizeof(str) << std::endl;

  // This returns 14 because strlen only returns the number of characters up to
  // and not including the terminating 0.
  std::cout << "length of the string = " << strlen(str) << std::endl;
}
