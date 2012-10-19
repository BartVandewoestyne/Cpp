/**
 * References:
 *
 *   [1] http://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/
 *
 * TODO: this doesn't run with g++ 4.6.2.
 */
#include <future>
#include <iostream>
#include <vector>

int twice(int m) {
  return 2 * m;
}

int main() {
  std::vector<std::future<int>> futures;

  for(int i = 0; i < 10; ++i) {
    futures.push_back (std::async(twice, i));
  }

  //retrive and print the value stored in the future
  for(auto &e : futures) {
    std::cout << e.get() << std::endl;
  }

  return 0;
}
