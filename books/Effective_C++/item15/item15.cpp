#include <iostream>
using namespace std;

int main()
{
  int i1, i2, i3;
  
  i1 = 1;
  i2 = 2;
  i3 = 3;

  (i1 = i2) = i3;  // legal!  assigns i2 to i1, then i3 to i1!

  cout << "i1 = " << i1 << endl;
  cout << "i2 = " << i2 << endl;
  cout << "i3 = " << i3 << endl;
}
