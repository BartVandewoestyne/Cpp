/**
 * Display bytes of a long to check endianness.
 *
 * Reference:
 *
 *   The Practice of Programming, Brian W. Kernighan and Rob Pike,
 *   Addison-Wesley, 1999, ISBN 0-201-61586-X, page 205.
 */

#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
  unsigned long x ;
  unsigned char *p;

  /* 11 22 33 44 => big-endian */
  /* 44 33 22 11 => little-endian */
  /* x = 0x1122334455667788UL; for 64-bit long */

  cout << "32-bit big-endian would be    11 22 33 44" << endl;
  cout << "32-bit little-endian would be 44 33 22 11" << endl;
  cout << "16-bit PDP-11 would be        22 11 44 33" << endl;
  cout << "You have: " << endl;

  x = 0x11223344UL;
  p = (unsigned char *) &x;
  for (size_t i = 0; i < sizeof(long); i++) {
    printf("%x ", *p++);
  }
  printf("\n");

  return 0;
}
