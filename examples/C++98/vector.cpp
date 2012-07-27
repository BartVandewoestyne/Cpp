/**
 * Illustrates the use of the vector class template and how we can iterate
 * in forward and backward direction.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/4205720/aesthetic-question-about-iterating-over-a-vector-in-reverse-direction
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

  vector<double>::size_type sz = myVector.size();
 

  cout << endl << "Forward listing" << endl;
  cout <<         "---------------" << endl;

  cout << endl << "Method 1: using a simple size_type index" << endl;
  for (vector<double>::size_type i = 0; i < sz; i++)
  { 
    // Checks for out of range are done here.
    cout << "value (checked index) = " << myVector.at(i) << endl;

    // No checks are done here.
    cout << "value (unchecked index) = " << myVector[i] << endl;
  }

  cout << endl << "Method 2: using iterators" << endl;
  for (vector<double>::iterator it = myVector.begin();
                                it != myVector.end();
                                ++it)
  {
    cout << "value = " << *it << endl;
  }


  // See also [1].
  cout << endl << "Reverse listing with index included" << endl;
  cout <<         "-----------------------------------" << endl;

  cout << endl
       << "Method 1: using reverse_iterator and extra index variable" << endl;
  vector<double>::size_type index = myVector.size() - 1;
  for (vector<double>::reverse_iterator rit = myVector.rbegin();
                                        rit < myVector.rend();
                                        ++rit, --index)
  {
    cout << "myVector[" << index << "] = " << *rit << endl;
  }

  cout << endl
       << "Method 2: Yves' solution 1" << endl;
  for (vector<double>::size_type i = sz; i > 0; --i)
  {
    cout << "myVector[" << i-1 << "] = " << myVector.at(i-1) << endl;
  }

  // When compiled with -Wall, this solution gives the warning:
  //
  //   warning: comparison between signed and unsigned integer expressions
  //
  // so it might not be 100% portable and safe...
  cout << endl
       << "Method 3: Yves' solution 2" << endl;
  for(vector<double>::size_type i = sz-1; i != -1; --i)
  {
    cout << "myVector[" << i << "] = " << myVector.at(i) << endl;
  }

  cout << endl
       << "Method 4: Yves' solution 3" << endl;
  for (int i = (int) myVector.size() - 1; i > -1; --i)
  {
    cout << "myVector[" << i << "] = " << myVector.at(i) << endl;
  }

  // This solution does not work because i is always >= 0 because it is of
  // size_type!!!
  cout << endl
       << "Method 5: not working" << endl;
  for (vector<double>::size_type i = sz - 1; i >= 0; --i)
  {
    cout << "myVector[" << i << "] = " << myVector.at(i) << endl;
  }

  return 0;
}
