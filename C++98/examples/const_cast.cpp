/*
 * A const_cast casts away the constness of its expression.
 *
 * References:
 *
 *   [20210802turner] C++ Weekly - Ep 283 - Stop Using const_cast!
 *     https://youtu.be/iuLwHoMFP_Y
 *
 *   [1] C++ Primer, 4th Edition, Lipman, Lajoi, Moo, 2005, section 5.12.6
 *   'Named Casts'.
 */

// If string_copy does not write its single parameter of type char*, then
// it would be best to correct it to take a const char*.  But suppose we
// didn't do that...
extern char* string_copy(char *in);

int main()
{
  const char *pc_str;

  // invalid conversion from ‘const char*’ to ‘char*’
  //char *pc = string_copy( pc_str );

  // We can cast away the constness here.  Now pc_str is a char*
  // instead of a const char*.
  char *pc = string_copy( const_cast<char*>(pc_str) );
}
