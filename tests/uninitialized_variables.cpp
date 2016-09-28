/*
 * Uninitialized variables cause undefined behavior.  This program can be used
 * to check typical values of uninitialized variables for different compilers.
 */

#include <iostream>

int main()
{
  bool b;
  std::cout << "uninitialized bool b = " << b << std::endl;

  unsigned char uc;
  std::cout << "uninitialized unsigned char = '" << uc << "'" << std::endl;

  unsigned int ui;
  std::cout << "uninitialized unsigned int = " << ui << std::endl;

  int i;
  std::cout << "uninitialized int = " << i << std::endl;

  float f;
  std::cout << "uninitialized float = " << f << std::endl;

  double d;
  std::cout << "uninitialized double = " << d << std::endl;
}
