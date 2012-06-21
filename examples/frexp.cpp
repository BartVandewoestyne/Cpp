/* frexp example */
#include <stdio.h>
#include <math.h>

int main ()
{
  double param, result;
  int n;

  param = 8.0;
  result = frexp (param , &n);
  printf ("%lf * 2^%d = %f\n", result, n, param);
  return 0;
}
