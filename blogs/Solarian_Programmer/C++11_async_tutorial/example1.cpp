/**
 * References:
 *
 *   [1] http://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/
 *
 * TODO: this doesn't run with g++ 4.6.2.
 */

#include <future>
#include <iostream>

void called_from_async() {
  std::cout << "Async call" << std::endl;
}

int main() {
  //called_from_async launched in a separate thread if possible
  std::future<void> result( std::async(called_from_async));

  std::cout << "Message from main." << std::endl;

  //ensure that called_from_async is launched synchronously 
  //if it wasn't already launched
  result.get();

  return 0;
}
