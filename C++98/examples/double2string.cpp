/**
 * Illustrates how a double can be converted to a string.
 */

#include <iostream>
#include <sstream>

using namespace std;
 
int main() {

  // This works.
  stringstream s1;
  s1 << 5.0;
  cout << s1.str() << endl;

  // This doesn't work.
  //string s2;
  //s2.append(" " + 5.0);

  return 0;

}
