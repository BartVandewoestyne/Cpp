/**
 * Example that illustrates what happens when iterating over
 * an empty vector.
 */
#include <iostream>
#include <vector>

using namespace std;
 
int main()
{
  vector<double> myVector;

  for (vector<double>::iterator it = myVector.begin();
                                it < myVector.end();
                                ++it)
  {
    cout << "We are iterating!" << endl;
  }

  return 0;
}
