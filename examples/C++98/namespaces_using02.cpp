/**
 * Illustrates how the keyword 'using' can also be used as a directive to
 * introduce an entire namespace.
 *
 * References:
 *   http://www.cplusplus.com/doc/tutorial/namespaces/
 */

#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {

  using namespace first;

  cout << x << endl;
  cout << y << endl;
  cout << second::x << endl;
  cout << second::y << endl;

  return 0;

}
