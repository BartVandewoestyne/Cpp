#include <iostream>
#include <iomanip>

int main()
{
  std::cout << std::scientific
            << std::showpoint
            << std::setw(25) << -0.1234567890
            << std::setw(25) << -0.1234567890 << std::endl;

  std::cout << std::fixed
            << std::setprecision(1)
            << 1.234 << std::endl;

  std::cout << std::setprecision(1)
            << 1.234 << std::endl;

  std::cout << std::showpoint
            << 1.234 << std::endl;

  std::cout << std::noshowpoint
            << std::setprecision(0)
            << 1.234 << std::endl;

  std::cout << std::setw(1) << 123 << std::endl;
  std::cout << std::setw(2) << 123 << std::endl;
  std::cout << std::setw(3) << 123 << std::endl;
  std::cout << std::setw(4) << 123 << std::endl;

  std::cout << std::setw(1) << "--" << std::endl;
  std::cout << std::setw(2) << "--" << std::endl;
  std::cout << std::setw(3) << "--" << std::endl;
  std::cout << std::setw(4) << "--" << std::endl;
}
