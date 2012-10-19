/**
 * References:
 *
 *   [1] http://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/
 *
 * TODO: this doesn't run with g++ 4.6.2.
 */
#include <future>
#include <iostream>

int main() {
  //called_from_async launched in a separate thread if possible
  std::future<int> result( std::async([](int m, int n) { return m + n;} , 2, 4));

  std::cout << "Message from main." << std::endl;

  //retrive and print the value stored in the future
  std::cout << result.get() << std::endl;

  return 0;
}
