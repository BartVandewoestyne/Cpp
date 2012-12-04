/*
 * PROBLEM 3
 * ---------
 * QUESTION:
 *   * Does the assert trigger?  What is the output?
 *
 * ANSWER:
 *   * The assert does not trigger.  The output is 4294967292, namely
 *     -4 + maximum size_t value + 1.
 */

#include <cassert>
#include <climits>
#include <limits>
#include <iostream>

using namespace std;

int main() {

  cout << "sizeof(int) = " << sizeof(int) << endl;
  cout << "sizeof(double) = " << sizeof(double) << endl;
  cout << "numeric_limits<size_t>::max() = " << numeric_limits<size_t>::max() << endl;
  cout << "(size_t)-1 = " << (size_t)-1 << endl;

  size_t n = sizeof(int) - sizeof(double);
  assert(n == -4);
  std::cout << n << std::endl;

  return 0;

}
