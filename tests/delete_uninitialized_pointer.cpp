/**
 * Test what happens if we delete an uninitialized pointer.  This should result
 * in undefined behavior.
 *
 * Compile with the -Wall option to see gcc's warning about this:
 *
 *   warning: ‘p’ is used uninitialized in this function
 */
int main()
{
  int *p;
  delete p;
}
