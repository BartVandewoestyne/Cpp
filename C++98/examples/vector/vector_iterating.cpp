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

int main()
{
  std::vector<double> myVector;
  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);

  std::vector<double>::size_type sz = myVector.size();
 

  std::cout << std::endl
            << "Forward listing" << std::endl;
  std::cout << "---------------" << std::endl;

  std::cout << std::endl << "Method 1: using iterators" << std::endl;
  for (std::vector<double>::iterator it = myVector.begin();
       it != myVector.end();
       ++it)
  {
    std::cout << "value = " << *it << std::endl;
  }

  std::cout << std::endl << "Method 2: using iterators, but saving on end() call" << std::endl;
  std::vector<double>::iterator iter = myVector.begin();
  std::vector<double>::iterator theEnd = myVector.end();
  for ( ; iter != theEnd; ++iter)
  {
    std::cout << "value = " << *iter << std::endl;
  }

  std::cout << std::endl << "Method 3: using iterators, but saving on end() call (Peter Niday approach)" << std::endl;
  std::vector<double>::iterator endIter;
  for (std::vector<double>::iterator iter = myVector.begin(),
       endIter = myVector.end(); iter != endIter; ++iter)
  {
    std::cout << "value = " << *iter << std::endl;
  }

  std::cout << std::endl << "Method 4: using a simple size_type index" << std::endl;
  for (std::vector<double>::size_type i = 0; i < sz; ++i)
  { 
    // Checks for out of range are done here.
    std::cout << "value (checked index) = " << myVector.at(i) << std::endl;

    // No checks are done here.
    std::cout << "value (unchecked index) = " << myVector[i] << std::endl;
  }

  // See also [1].
  std::cout << std::endl
            << "Reverse listing with index included" << std::endl;
  std::cout << "-----------------------------------" << std::endl;

  std::cout << std::endl
            << "Method 1: using reverse_iterator and extra index variable" << std::endl;
  std::vector<double>::size_type index = myVector.size() - 1;
  for (std::vector<double>::reverse_iterator rit = myVector.rbegin();
       rit < myVector.rend();
       ++rit, --index)
  {
    std::cout << "myVector[" << index << "] = " << *rit << std::endl;
  }

  std::cout << std::endl
            << "Method 2: Yves' solution 1" << std::endl;
  for (std::vector<double>::size_type i = sz; i > 0; --i)
  {
    std::cout << "myVector[" << i-1 << "] = " << myVector.at(i-1) << std::endl;
  }

  // When compiled with -Wall, this solution gives the warning:
  //
  //   warning: comparison between signed and unsigned integer expressions
  //
  // so it might not be 100% portable and safe...
  std::cout << std::endl
            << "Method 3: Yves' solution 2" << std::endl;
  for(std::vector<double>::size_type i = sz-1; i != -1; --i)
  {
    std::cout << "myVector[" << i << "] = " << myVector.at(i) << std::endl;
  }

  std::cout << std::endl
            << "Method 4: Yves' solution 3" << std::endl;
  for (int i = (int) myVector.size() - 1; i > -1; --i)
  {
    std::cout << "myVector[" << i << "] = " << myVector.at(i) << std::endl;
  }

  // This solution does not work because i is always >= 0 because it is of
  // size_type!!!
  std::cout << std::endl
            << "Method 5: not working" << std::endl;
  for (std::vector<double>::size_type i = sz - 1; i >= 0; --i)
  {
    std::cout << "myVector[" << i << "] = " << myVector.at(i) << std::endl;
  }

  return 0;
}
