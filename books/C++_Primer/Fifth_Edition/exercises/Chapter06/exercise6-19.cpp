#include <string>
#include <vector>
using namespace std;

double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);

int main()
{
  // a: error: too many arguments to function ‘double calc(double)’
  //calc(23.4, 55.1);

  // b: OK
  count("abcda", 'a');

  // c: OK
  calc(66);

  // d: OK, but 3.8 gets truncated to 3.
  sum(vec.begin(), vec.end(), 3.8);
}
