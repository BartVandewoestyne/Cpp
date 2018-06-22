#include <vector>

int main()
{
  int x[] = {1, 2, 3};

  std::vector<int> v(std::begin(x), std::end(x));
}
