/**
 * Illustrates the use of lambda expressions.
 *
 * References:
 *
 *   [microsoft] Lambda expressions in C++
 *   http://msdn.microsoft.com/en-us/library/dd293608.aspx
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
using namespace std;

int main() 
{
  // Create a vector object that contains 10 elements.
  vector<int> v;
  for (int i = 0; i < 10; ++i) 
  {
    v.push_back(i);
  }

  // Count the number of even numbers in the vector by 
  // using the for_each function and a lambda expression.
  int evenCount = 0;
  for_each(v.begin(), v.end(), [&evenCount] (int n) {
    cout << n;

    if (n % 2 == 0) 
    {
      cout << " is even " << endl;

      // Increment the counter.
      evenCount++;
    }
    else 
    {
      cout << " is odd " << endl;
    }
  });

  // Print the count of even numbers to the console.
  cout << "There are " << evenCount 
       << " even numbers in the vector." << endl;

}
