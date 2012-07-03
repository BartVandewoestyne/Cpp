/**
 * Demonstrate the use of complex numbers.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/1641819/why-is-complexdouble-int-not-defined-in-c
 */

#include <iostream>
#include <complex>

using namespace std;

int main()
{
  complex<double> a(1, 1);
  complex<double> b(3, 0);
  double c = 4;

  // This gives the compiler-error:
  //   error: missing template arguments before ‘b’
  //complex b(3, 0);

  cout << a << endl;
  cout << b << endl;

  cout << a.real() << endl;
  cout << a.imag() << endl;

  // This works.
  cout << a/b << endl;
  cout << a/3.0 << endl;

  // This gives the error:
  //   error: no match for ‘operator/’ in ‘a / 3’
  //cout << a/3 << endl;

  // This works.
  cout << a*4.0 << endl;
  cout << a*c << endl;

  // This gives the error:
  //   error: no match for ‘operator*’ in ‘a * 4’
  //cout << a*4 << endl;

  // This works.
  cout << a-1.0 << endl;
  cout << a-c << endl;

  // This gives the error:
  //   error: no match for ‘operator-’ in ‘a - 1’
  //cout << a-1 << endl;

  // Creating a literal constant using the constructor of complex.
  cout << complex<double>(1.2,3.4) << endl;

  return 0;

}
