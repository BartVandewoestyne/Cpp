/**
 * Illustrates how the keyword 'using' is used to introduce a name from a
 * namespace into the current declarative region.
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

  using first::x;
  using second::y;

  cout << x << endl;
  cout << y << endl;
  cout << first::y << endl;
  cout << second::x << endl;

  return 0;

}
