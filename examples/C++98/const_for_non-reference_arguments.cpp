/*
 * Example that illustrates how using const for non-reference parameters is
 * about self-documenting your code and your assumptions.
 *
 * References:
 *
 *   [scocco2012] Isn't 'const' redundant when passing by value?
 *                https://stackoverflow.com/questions/8714250/isnt-const-redundant-when-passing-by-value
 *
 *   [samaursa2011] const for non-reference arguments
 *                  https://stackoverflow.com/questions/6125425/const-for-non-reference-arguments
 *
 *   [rob2008] Use of 'const' for function parameters
 *             https://stackoverflow.com/questions/117293/use-of-const-for-function-parameters
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
