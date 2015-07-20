/**
 * Example illustrating inline functions.
 * 
 * References:
 *   [1] http://stackoverflow.com/questions/145838/benefits-of-inline-functions-in-c
 *   [2] http://stackoverflow.com/questions/1932311/when-to-use-inline-function-and-when-not-to-use-it
 *   [3] http://www.gotw.ca/gotw/033.htm
 *
 * Remarks:
 *   - marking something inline does not give you a guarantee that it will be
 *     inline, it's just a suggestion to the compiler.
 *
 * Advantages of inline functions:
 *   - they often make your code faster
 *
 * Disadvantages of inline functions:
 *   - they often make the binary slightly larger
 *
 * TODO: further test and improve this example.
 */

inline int aplusb_pow2(int a, int b)
{
  return (a+b)*(a+b);
}

int main()
{
  for (int a = 0; a < 900000; ++a)
    for (int b = 0; b < 900000; ++b)
      aplusb_pow2(a, b);
}
