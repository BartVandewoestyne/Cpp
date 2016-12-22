#include <stdio.h>

int main ()
{
  char buffer [100];
  int cx;

  cx = snprintf(buffer, 100, "The half of %d is %d", 60, 60/2);

  if (cx >= 0 && cx < 100)      // check returned value

    snprintf (buffer + cx, 100 - cx, ", and the half of that is %d.", 60/2/2);

  puts (buffer);

  return 0;
}
