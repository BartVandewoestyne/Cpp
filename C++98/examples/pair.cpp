/*
 * Example on how to use std::pair.
 *
 * References:
 *
 *   [1] http://www.cplusplus.com/reference/utility/pair/pair/
 *
 *   [mertz2017] Smelly std::pair and std::tuple
 *     https://arne-mertz.de/2017/03/smelly-pair-tuple/
 *
 *   [isaacson20131106] std::pair considered harmful!
 *     http://maintainablecode.logdown.com/posts/158531-stdpair-considered-harmful
 */

#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
  std::pair <std::string, double> product1;                    // default constructor
  std::pair <std::string, double> product2("tomatoes", 2.30);  // value init
  std::pair <std::string, double> product3(product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"), 0.99);  // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  return 0;
}
