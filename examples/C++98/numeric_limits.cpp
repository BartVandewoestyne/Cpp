/**
 * Reference:
 *
 *   [1] http://www.cplusplus.com/reference/std/limits/numeric_limits/
 */
#include <iostream>
#include <limits>
using namespace std;

int main () {
  cout << boolalpha;
  cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
  cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
  cout << "int is signed: " << numeric_limits<int>::is_signed << endl;
  cout << "Non-sign bits in int: " << numeric_limits<int>::digits << endl;
  cout << "int has infinity: " << numeric_limits<int>::has_infinity << endl;
  cout << "double has infinity: " << numeric_limits<double>::has_infinity << endl;
  cout << "representation of positive infinity: " << numeric_limits<double>::infinity() << endl;
  return 0;
}
