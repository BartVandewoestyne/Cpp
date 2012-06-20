/**
 * (*1.5) What happens if you divide by zero on your system?  What happens in
 * case of overflow and underflow?
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <cfloat>

using namespace std;

int main()
{
  int x = 0;

  // Division by zero gives a floating point exception.
  //cout << " 1/0 = " << 1/x << endl;

  // When overflow or underflow occurs for integers, we flip
  // over to the other side of the range.
  cout << "int:" << endl;
  cout << "numeric_limits<int>::min()-1 = " << setw(15)
       << numeric_limits<int>::min()-1 << endl;
  cout << "numeric_limits<int>::min()   = " << setw(15)
       << numeric_limits<int>::min()   << endl;
  cout << "numeric_limits<int>::min()+1 = " << setw(15)
       << numeric_limits<int>::min()+1 << endl;
  cout << "numeric_limits<int>::max()-1 = " << setw(15)
       << numeric_limits<int>::max()-1 << endl;
  cout << "numeric_limits<int>::max()   = " << setw(15)
       << numeric_limits<int>::max()   << endl;
  cout << "numeric_limits<int>::max()+1 = " << setw(15)
       << numeric_limits<int>::max()+1 << endl;


  // For floating types with denormalization (variable number of exponent bits):
  // the min() function returns the minimum positive *normalized* value.
  cout << "float:" << endl;
  cout << "numeric_limits<float>::min() = "
       << numeric_limits<float>::min() << endl;
  cout << "FLT_MIN = " << FLT_MIN << endl;
  cout << "numeric_limits<float>::max() = "
       << numeric_limits<float>::max() << endl;
  cout << "FLT_MAX = " << FLT_MAX << endl;


  // Try to reach underflow... doesn't seem to work,
  // y seems to become zero.
  float y = numeric_limits<float>::min();
  while ( y != 0 )
  {
    y = y/2;
    cout << "y = " << y << endl;
  }

  // Try to reach overflow... doesn't seem to work,
  // z seems to become 'inf'.
  float z = numeric_limits<float>::max();
  for (int i = 0; i < 10; i++)
  {
    z = z*2;
    cout << "z = " << z << endl;
  }

}
