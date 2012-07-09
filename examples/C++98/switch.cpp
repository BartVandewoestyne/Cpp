#include <iostream>
using namespace std;

int main()
{
  int i = 1;
  switch (i)
  {
    case 1:
      cout << "i is 1" << endl;
      break;

    case 2:
      cout << "i is 2" << endl;
      break;

    default:
      // If the default case does not contain any statements, this results
      // in an error at compile time.  At least one statement (which can be the
      // empty statement) must be present.
      //cout << "i was not 1 and not 2" << endl;
      break;
      //;
  }
}
