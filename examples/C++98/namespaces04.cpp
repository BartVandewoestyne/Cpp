/**
 * Illustrates how 'using' and 'using namespace' have validity only in the
 * same block in which they are stated or in the entire code if they are used
 * directly in the global scope.
 *
 * References:
 *   http://www.cplusplus.com/doc/tutorial/namespaces/
 */

#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
}

namespace second
{
  double x = 3.1416;
}

int main () {
  {
    using namespace first;
    cout << x << endl;
  }
  {
    using namespace second;
    cout << x << endl;
  }
  return 0;
}
