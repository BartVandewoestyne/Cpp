/**
 * (*1) See how your compiler reacts to these errors.  Devise more simple
 * errors and see how the compiler reacts.
 *
 * Compile with:
 *
 *   g++ -c ch06ex11.cpp
 * 
 * or
 *
 *   g++ -c -Wall ch06ex11.cpp
 */

void f(int a, int b)
{

  // Assignment instead of comparison.
  // Compiler doesn't see this as an error, but gives the following warning
  // if the -Wall option is used:
  //
  //   warning: suggest parentheses around assignment used as truth value
  //
  if (a = 3) {}

  // Here, the bitwise operation is applied *after* the equality comparison.
  if (a&077==0) {}

  // error: expected primary-expression before ‘=’ token
  //a := b + 1;

}
