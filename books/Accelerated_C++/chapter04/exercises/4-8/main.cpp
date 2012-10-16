/**
 * 4-8. If the following code is legal, what can we infer about the return type
 * of f?
 *
 *     double d = f()[n];
 *
 * Answer: the return type of f must be a vector or a ref to a vector?
 */

#include <vector>
#include <iostream>

// Possibility 1?
std::vector<int> f(void)
{
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  return v;
}

// Possibility 2?
//std::vector<int>& f()
//{
//  std::vector<int> *v = new std::vector<int>;
//  v->push_back(1);
//  v->push_back(2);
//  return *v;
//}

int main()
{
  int n = 1;
  double d = f()[n];
  std::cout << d << std::endl;
}
