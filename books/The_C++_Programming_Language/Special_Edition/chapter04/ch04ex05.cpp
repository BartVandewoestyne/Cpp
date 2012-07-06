/*
 * TODO: improve output.
 */
#include <limits>
#include <iostream>

int main ()
{
  std::cout << "smallest char = " << std::numeric_limits<char>::min() << " (" << int(std::numeric_limits<char>::min()) << ")" << '\n';
  std::cout << "largest char  = " << std::numeric_limits<char>::max() << " (" << int(std::numeric_limits<char>::max()) << ")" << '\n';

  std::cout << "smallest short = " << std::numeric_limits<short>::min() << '\n';
  std::cout << "largest short  = " << std::numeric_limits<short>::max() << '\n';

  std::cout << "smallest int = " << std::numeric_limits<int>::min() << '\n';
  std::cout << "largest int  = " << std::numeric_limits<int>::max() << '\n';

  std::cout << "smallest long = " << std::numeric_limits<long>::min() << '\n';
  std::cout << "largest long  = " << std::numeric_limits<long>::max() << '\n';

  std::cout << "smallest float = " << std::numeric_limits<float>::min() << '\n';
  std::cout << "largest float  = " << std::numeric_limits<float>::max() << '\n';

  std::cout << "smallest double = " << std::numeric_limits<double>::min() << '\n';
  std::cout << "largest double = " << std::numeric_limits<double>::max() << '\n';

  std::cout << "smallest long double = " << std::numeric_limits<long double>::min() << '\n';
  std::cout << "largest long double = " << std::numeric_limits<long double>::max() << '\n';

  std::cout << "smallest unsigned = " << std::numeric_limits<unsigned>::min() << '\n';
  std::cout << "largest unsigned = " << std::numeric_limits<unsigned>::max() << '\n';
}
