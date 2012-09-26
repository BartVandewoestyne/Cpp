/*
 * References:
 *   [1] http://yapb-soc.blogspot.de/2012/09/range-based-for-loop-on-int-range.html
 */

#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  vector<int> vec;
  vec.push_back( 10 );
  vec.push_back( 20 );
  
  for (int &i : vec ) 
  {
    cout << i << endl;
  }

  for (auto i : { 2, 4, 5, 7 })
  {
    cout << i << endl;
  }

  for (int x : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
  {
    cout << x << endl;
  }

}
