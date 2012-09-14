#include "Rational.h"

int main()
{
  Rational oneEight(1, 8);
  Rational oneFourth(1, 4);
  Rational oneHalf(1, 2);

  Rational result = oneHalf * oneEight;
  result = result * oneEight;

  result = oneHalf * 2;
  result = 2 * oneHalf;

  result = oneFourth * 2;
  result = 2 * oneFourth;
}
