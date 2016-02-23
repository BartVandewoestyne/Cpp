/*
 * Simple program that creates a vector and adds some elements to it.
 */

#include <vector>

int main()
{
  std::vector<double> myVector;

  myVector.push_back(1);
  myVector.push_back(2);
  myVector.push_back(3);

  std::vector<double>::size_type sz = myVector.size();
 
  return 0;
}
