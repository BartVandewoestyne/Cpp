/**
 * Illustrates how in C++11 we can use auto to iterate over a vector.
 *
 * References:
 *
 *   [1] http://my.collaboration.agilent.com/personal/tparker/Blog
 */

#include <iostream>
#include <vector>

int main()
{
  std::vector<double> myVector;
  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);

  for (auto iter = myVector.begin(); iter != myVector.end(); ++iter)
  {
    std::cout << *iter << std::endl;
  }

  // If the code does not want to modify the value inside the container.
  for (auto val: myVector)
  {
    std::cout << val << std::endl;
  }

  // If the code does want to modify the value inside the container.
  for (auto& val: myVector)
  {
    std::cout << val << std::endl;
  }

  return 0;
}
