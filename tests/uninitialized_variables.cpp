/*
 * Uninitialized variables cause undefined behavior.  This script can be used to
 * check typical values of uninitialized variables for different compilers.
 */

#include <iostream>

int main()
{
  bool b;
  std::cout << "bool b: " << b << std::endl;

  unsigned char uc;
  std::cout << "unsigned char: [" << uc << "]" << std::endl;

  unsigned int ui;
  std::cout << "unsigned int ui: " << ui << std::endl;

  double d;
  std::cout << "double: " << d << std::endl;
}
