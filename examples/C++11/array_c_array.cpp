/*!
 * Program to illustrate how you can use the free function templates std::begin
 * and std::end on an ordinary C-array.  Since std::begin and std::end return
 * iterators for a C-array, a C-array is quite comfortable and safe to use with
 * these function templates because you do not have to remember its size.
 *
 * References:
 *
 *   [1] http://www.modernescpp.com/index.php/std-array-dynamic-memory-no-thanks
 */

#include <algorithm>
#include <iostream>

int main(){

  // Initialize an ordinary C-array, NOT a std::array!
  int array[] = {1, 2, 3, 4, 5, 6 ,7, 8};

  // Print the array.
  std::for_each(std::begin(array), std::end(array), [](int v){ std::cout << v << " "; });
  std::cout << std::endl;

  // Calculate the sum of the array using a global variable.
  int sum = 0;
  std::for_each(std::begin(array), std::end(array), [&sum](int v){ sum += v; });
  std::cout << "sum = " << sum << std::endl;

  // Change each array element to its second power.
  std::for_each(std::begin(array), std::end(array), [](int& v){ v = v*v; });
  std::for_each(std::begin(array), std::end(array), [](int v){ std::cout << v << " "; });
  std::cout << std::endl;

}
