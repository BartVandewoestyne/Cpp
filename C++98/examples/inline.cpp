/**
 * Example illustrating inline functions.
 * 
 * References:
 *
 *   [TimurHu20200730] Should you use the inline keyword or not?
 *     https://www.reddit.com/r/cpp/comments/i0haek/should_you_use_the_inline_keyword_or_not/
 *
 *   [brand20180126] Do compilers take inline as a hint?
 *     https://blog.tartanllama.xyz/inline-hints/
 *
 *   [devilliers20150219] Benefits of inline functions in C++?
 *     http://stackoverflow.com/questions/145838/benefits-of-inline-functions-in-c
 *
 *   [ashish20091219] When to use inline function and when not to use it?
 *     http://stackoverflow.com/questions/1932311/when-to-use-inline-function-and-when-not-to-use-it
 *
 *   [sutter2002] More Exceptional C++
 *     http://www.gotw.ca/publications/mxc++.htm
 *
 *   [sutter19980322] GotW #33: Inline
 *     http://www.gotw.ca/gotw/033.htm
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
  const int n_max = 100000;

  for (int a = 0; a < n_max; ++a)
    for (int b = 0; b < n_max; ++b)
      aplusb_pow2(a, b);
}
