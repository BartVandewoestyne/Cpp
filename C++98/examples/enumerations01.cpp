#include <iostream>
using namespace std;

enum Color {
  COLOR_BLACK,
  COLOR_WHITE,
  COLOR_RED
};

int main()
{

  Color myColor;

  myColor = COLOR_BLACK;
  cout << myColor << endl;

  myColor = COLOR_WHITE;
  cout << myColor << endl;

  myColor = COLOR_RED;
  cout << myColor << endl;

  // The statement below returns the error:
  //
  //   error: invalid conversion from ‘int’ to ‘Color’ [-fpermissive]
  //
  // The use of enumerations protects us against assignments like this.
  //myColor = 1;

  return 0;

}
