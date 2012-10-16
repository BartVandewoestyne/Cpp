/**
 * 4-7. Write a program to calculate the average of the numbers stored in a
 * vector<double>.
 */

#include <vector>
#include <iostream>

double average(const std::vector<double>& v)
{
  double sum = 0;
  for (std::vector<double>::const_iterator it=v.begin();
       it < v.end();
       it++)
  {
    sum += *it;
  }
  return sum/v.size();
}

int main()
{
  std::vector<double> numbers;
  numbers.push_back(1.0);
  numbers.push_back(2.0);
  numbers.push_back(3.0);
  std::cout << "Average = " << average(numbers) << std::endl;
}
