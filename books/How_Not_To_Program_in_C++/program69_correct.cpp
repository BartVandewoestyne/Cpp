/************************************************
 * sum_test -- Test the sum function            *
 ************************************************/
#include <stdio.h>

/************************************************
 * sum -- Sum up three numbers                  *
 *                                              *
 * Returns: The sum of the numbers.             *
 ************************************************/
int sum(int i1, int i2, int i3)
{
   return (i1 + i2 + i3);
}

int main()
{
   printf("Sum is %d\n", sum(1, 2, 3));
   return (0);
}
