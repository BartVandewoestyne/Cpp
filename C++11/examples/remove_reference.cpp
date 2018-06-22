/*
 * References:
 *
 *   [1] http://en.cppreference.com/w/cpp/types/remove_reference
 */
#include <iostream> // std::cout
#include <type_traits> // std::is_same
 
template<class T1, class T2>
void print_is_same() {
  std::cout << std::is_same<T1, T2>() << '\n';
}
 
int main() {
  std::cout << std::boolalpha;
 
  print_is_same<int, int>();    // true
  print_is_same<int, int &>();  // false
  print_is_same<int, int &&>(); // false
 
  print_is_same<int, std::remove_reference<int>::type>();    // true
  print_is_same<int, std::remove_reference<int &>::type>();  // true
  print_is_same<int, std::remove_reference<int &&>::type>(); // true
}
