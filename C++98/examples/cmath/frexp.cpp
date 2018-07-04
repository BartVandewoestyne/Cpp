/**
 * Demonstrates the use of the std::frexp library function.
 */

#include <cstdio>
#include <cmath>

int main ()
{
  double param;
  double result;
  int n;

  param = 8.0;
  result = std::frexp(param , &n);

  std::printf("%lf * 2^%d = %f\n", result, n, param);

  return 0;
}
