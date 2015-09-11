/*
 * Example illustrating how adjacent string literals are concatenated.
 *
 * References:
 *
 *   [1] ISO/IEC 1482:2003, section 2.13.4, item 3.
 */

#include <iostream>

int main()
{
  const char* s = "Hello" "world";

  std::cout << s << std::endl;
}
