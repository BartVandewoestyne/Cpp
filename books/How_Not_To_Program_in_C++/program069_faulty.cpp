/************************************************
 * sum_test -- Test the sum function            *
 ************************************************/
#include <stdio.h>

/************************************************
 * sum -- Sum up three numbers                  *
 *                                              *
 * Returns: The sum of the numbers.             *
 ************************************************/
int sum(i1, i2, i3)
{
   int i1;      /* The first number */
   int i2;      /* The second number */
   int i3;      /* The third number */

   return (i1 + i2 + i3);
}

int main()
{
   printf("Sum is %d\n", sum(1, 2, 3));
   return (0);
}
