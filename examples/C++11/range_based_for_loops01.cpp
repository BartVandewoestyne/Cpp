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
    cout << i;
  }

  for (auto i : { 2, 4, 5, 7 }) {
  }

}
