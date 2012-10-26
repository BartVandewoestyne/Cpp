#include <iostream>
#include <iomanip>

int main()
{
  std::cout << std::scientific
            << std::showpoint
            << std::setw(25) << -0.1234567890
            << std::setw(25) << -0.1234567890 << std::endl;
}
