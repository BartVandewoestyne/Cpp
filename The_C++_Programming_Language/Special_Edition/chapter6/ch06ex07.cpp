/* 
 * (*2) Write 5 expressions for which the order of evaluation is undefined.
 * Execute them to see what one or - preferably - more implementations do with
 * them.
 *
 * TODO:
 *   - add more examples.
 */
#include <iostream>

using namespace std;

int f(int x)
{
  cout << "Executing f(x)" << endl;
  return 0;
}

int g(int x)
{
  cout << "Executing g(x)" << endl;
  return 0;
}

int f1(int x, int y)
{
  cout << "x + y = " << x + y << endl;
}

int main()
{
  /* Example 1. */
  int x = f(2) + g(3);

  /* Example 2. */
  int v[3] = {1, 2, 3};
  int i = 1;
  // This can be v[1] = 1 or v[2] = 1 or may cause even stranger behavior.
  v[i] = i++;

  /* Example 3: order dependence of argument expressions. */
  i = 1;
  f1(v[i],i++);

}
