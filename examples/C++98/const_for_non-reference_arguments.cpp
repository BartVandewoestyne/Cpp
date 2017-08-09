/*
 * References:
 *   [samaursa2011] https://stackoverflow.com/questions/6125425/const-for-non-reference-arguments
 */

void f(const int x, int y)
{
  //x = 1;  // Error!
  y = 2;    // Without const, no error message for this.
}

int main()
{
    f(4, 5);
}
