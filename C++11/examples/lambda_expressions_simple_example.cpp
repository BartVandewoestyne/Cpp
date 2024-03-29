/**
 * Illustrates the use of lambda expressions.
 *
 * References:
 *
 *   [microsoft] Lambda expressions in C++
 *     http://msdn.microsoft.com/en-us/library/dd293608.aspx
 *
 *   [kristofik20230201] Modern C++ In-Depth — Lambdas, Part 3
 *     https://medium.com/factset/modern-c-in-depth-lambdas-part-3-561823a990e6
 *
 *   [kristofik20230106] Modern C++ In-Depth — Lambdas, Part 2
 *     https://medium.com/factset/modern-c-in-depth-lambdas-part-2-a2d54c7b51
 *
 *   [adusumilli20221129] Modern C++ In-Depth — Lambdas, Part 1
 *     https://medium.com/factset/modern-c-in-depth-lambdas-part-1-d03fe8153ee1
 *
 *   [nurak20211117] Lambda expressions in modern C++ (in depth step by step tutorial)
 *     https://youtu.be/MH8mLFqj-n8
 *
 *   [jain20170723] Lambdas in C++
 *     https://mayankj08.github.io/2017/07/23/Lambdas-In-C++/
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
  // Create a vector object that contains 10 elements.
  std::vector<int> v;
  for (int i = 0; i < 10; ++i) 
  {
    v.push_back(i);
  }

  // Count the number of even numbers in the vector by 
  // using the for_each function and a lambda expression.
  int evenCount = 0;
  std::for_each(v.begin(), v.end(), [&evenCount] (int n) {
    std::cout << n;

    if (n % 2 == 0) 
    {
      std::cout << " is even " << std::endl;
      evenCount++;
    }
    else 
    {
      std::cout << " is odd " << std::endl;
    }
  });

  // Print the count of even numbers to the console.
  std::cout << "There are " << evenCount 
       << " even numbers in the vector." << std::endl;

}
