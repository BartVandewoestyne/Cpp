/**
 * Demonstrate the use of complex numbers.
 */

#include <iostream>
#include <complex>

using namespace std;

int main()
{
  complex<double> a(1, 1);
  complex<double> b(3, 0);

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

  // Creating a literal constant using the constructor of complex.
  cout << complex<double>(1.2,3.4) << endl;

  return 0;

}
