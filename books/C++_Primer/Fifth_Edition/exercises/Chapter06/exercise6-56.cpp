// TODO: check if this is correct.

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return x / y; }

int main()
{
  vector<int(*)(int, int)> v;

  v.push_back(add);
  v.push_back(subtract);
  v.push_back(multiply);
  v.push_back(divide);

  cout << v[0](1, 2) << endl;
  cout << v[1](1, 2) << endl;
  cout << v[2](1, 2) << endl;
  cout << v[3](1, 2) << endl;
}
