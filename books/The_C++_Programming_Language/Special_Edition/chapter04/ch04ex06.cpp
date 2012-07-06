int main ()
{

/* 
 * C++ imposes no limit on the number of charac- ters in a name. However, some
 * parts of an implementation are not under the control of the com- piler writer
 * (in particular, the linker), and those parts, unfortunately, sometimes do
 * impose limits.  Some run-time environments also make it necessary to extend
 * or restrict the set of characters accepted in an identifier. Extensions
 * (e.g., allowing the character $ in a name) yield nonportable programs.
 */

  // this doesn't give compiler errors.
  int a1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890;

  // this doesn't give compiler errors.
  extern int a12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890;

}
