/*
 * PROBLEM 1
 * ---------
 * A) These three asserts are algebraically equivalent.  Some trigger and some
 *    do not.  Why?
 * B) These two asserts are algebraically opposite.  Why is their assert
 *    behavior the same?
 * C) The first assert is stricter than the second.  Why is the second one
 *    the only one that triggers?
 *
 * ANSWER:
 *   * According to the 'usual arithmetic conversions', the signed int is
 *     converted to unsigned int.  Converting a negative signed int to an
 *     unsigned int is done by adding UINT_MAX + 1. (See also section 4.7
 *     'Integral conversions' in the C++ standard).
 */

#include <cassert>
#include <iostream>
#include <climits>

using namespace std;

int main() {

  int i = -6;
  unsigned n = 3;

  cout << "UINT_MAX = 2^32-1 = " << UINT_MAX << endl;
  cout << "-6 + UINT_MAX + 1 = " << -6 + UINT_MAX + 1 << endl;
  cout << "static_cast<int>(n) = " << static_cast<int>(n) << endl;
  cout << "static_cast<unsigned>(i) = " << static_cast<unsigned>(i) << endl;
  cout << "static_cast<unsigned>(-3) = " << static_cast<unsigned>(-3) << endl;
  cout << "n - i = " << n - i << endl;
  cout << "i - n = " << i - n << endl;
  cout << "i + n = " << i + n << endl;

  //assert(i < n);      // triggers because -6 gets converted to 4294967290
  //assert(i - n < 0);  // triggers because i - n = 4294967287
  //assert(0 < n - i);  // does not trigger because n - i = 9

  //assert(0 < n - i );  // does not trigger because n - i = 9
  //assert(0 <= i - n ); // does not trigger because i - n = 4294967287

  //assert(i + n == -3); // does not trigger because i + n = 4294967293 = -3
  //assert(i + n < 0);   // triggers because i + n = 4294967293

  return 0;

}
