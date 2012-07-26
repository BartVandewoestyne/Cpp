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
    // Checks for out of range are done here.
    cout << "value = " << myVector.at(i) << endl;

    // No checks done here.
    cout << "value = " << myVector[i] << endl;
  }

  // Method 2: using iterators.
  for (vector<double>::iterator it = myVector.begin();
                                it != myVector.end();
                                ++it)
  {
    cout << "value = " << *it << endl;
  }

  // Reverse listing of the elements, with the need for the index.
  cout << "Reverse listing" << endl;
  //
  // See also http://stackoverflow.com/questions/4205720/aesthetic-question-about-iterating-over-a-vector-in-reverse-direction
  //
  // Method 1: this does not work because i is always >= 0 since it is of
  // size_type!!!
  //for (vector<double>::size_type i = sz - 1; i >= 0; --i)
  //{
  //  cout << "i = " << i << endl;
  //  cout << myVector.at(i) << endl;
  //}
  // Method 2: use reverse iterator
  vector<double>::size_type index = myVector.size() - 1;
  for (vector<double>::reverse_iterator rit = myVector.rbegin();
                                        rit != myVector.rend();
                                        ++rit, --index)
  {
    cout << "value = " << *rit << endl;
    cout << "index = " << index << endl;
  }

 
  return 0;
}
