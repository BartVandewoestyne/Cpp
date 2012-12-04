/*
 * PROBLEM 7
 * ---------
 * QUESTION:
 *   * You want to store up to 64 bits in an integer.  Which of the following
 *     data types work for that?
 *
 * ANSWER:
 *   * The C++ standard defines minimum ranges, from which one can deduce
 *     the minimum number of bits (since the number system is base 2 for
 *     the C++ integer datatypes):
 *
 *       long: -2147483647 to 2147483647 -> 32 bits
 *       unsigned long: 0 to 4294967295 -> 32 bits
 *       long long: -9223372036854775807 to 9223372036854775807 -> 64 bits
 *       unsigned long long: 0 to 18446744073709551615 -> 64 bits
 *       size_t: 0 to 65535 (see C99 standard) -> 16 bits
 *
 * NOTES BART:
 *   * Could it be that you forgot variable names (I called them x1,...,x5) ???
 *
 * REFERENCES:
 *   * http://stackoverflow.com/questions/589575/size-of-int-long-etc
 *   * http://en.wikipedia.org/wiki/C_data_types#Size_and_pointer_difference_types
 */

#include <cstddef>
#include <iostream>

using namespace std;

int main() {

  long               x1 = 0xff00ee00dd00cc00; // Not safe.
  unsigned long      x2 = 0xff00ee00dd00cc00; // Not safe.
  long long          x3 = 0xff00ee00dd00cc00; // Safe.
  unsigned long long x4 = 0xff00ee00dd00cc00; // Safe.
  size_t             x5 = 0xff00ee00dd00cc00; // Note safe.

  cout << "On my system:" << endl;
  cout << "sizeof(long)               = " << sizeof(long) << endl;
  cout << "sizeof(unsigned long)      = " << sizeof(unsigned long) << endl;
  cout << "sizeof(long long)          = " << sizeof(long long) << endl;
  cout << "sizeof(unsigned long long) = " << sizeof(unsigned long long) << endl;
  cout << "sizeof(size_t)             = " << sizeof(size_t) << endl;

  return 0;

}
