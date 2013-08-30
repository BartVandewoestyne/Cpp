// TODO: check if this is correct.

#include <vector>
using std::vector;

int f(int, int);

int main()
{
  int (*pf)(int, int);

  vector<int(*)(int, int)> v;
}
