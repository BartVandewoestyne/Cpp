/* ldexp example */
#include <stdio.h>
#include <math.h>

int main ()
{
  double param, result;
  int n;

  param = 0.95;
  n = 4;
  result = ldexp (param , n);
  printf ("%f * 2^%d = %f\n", param, n, result);
  return 0;
}
