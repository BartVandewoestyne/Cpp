/**
 * Illustrates the use of the vector class template.
 */

#include <iostream>
#include <vector>

using namespace std;
 
int main()
{
  vector<double> myVector;

  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);
 
  // Method 1: using a simple index.
  //
  // Note that we call size() before the loop, so that this size() function
  // is executed only once.
  vector<double>::size_type sz = myVector.size();
  for (vector<double>::size_type i = 0; i < sz; i++)
  {
    cout << myVector.at(i) << endl;  // Checks for out of range are done here.
    cout << myVector[i] << endl;     // No checks done here.
  }

  // Method 2: using iterators.
  for (vector<double>::iterator it = myVector.begin();
                                it != myVector.end();
                                ++it)
  {
    cout << *it << endl;
  }
 
  return 0;
}
