/**
 * Demonstrates what const variables are and how they can be declared.
 *
 * References:
 *   [1] http://www.bfilipek.com/2016/12/please-declare-your-variables-as-const.html
 */

int main() {

  /* A non-const variable can be modified. */
  int x = 1;
  x = 2;

  /* A const variable can be initialized, but not modified thereafter. */
  const int y = 1;
  //y = 2;  // "error: assignment of read-only variable ‘y’"

  /* One can put the 'const' keyword either before or after the type, so this
     is also valid. */
  int const z = 1;
  //z = 2;  // "error: assignment of read-only variable ‘z’"

  return 0;

}
