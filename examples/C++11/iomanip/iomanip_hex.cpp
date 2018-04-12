#include <cstdint>
#include <iostream>
#include <iomanip>
#include <sstream>

template <typename T>
void printUsingCout()
{
  for (T i = 0; i < 16; ++i)
  {
    std::cout << std::hex << std::setfill('0') << std::setw(2) << static_cast<int>(i);
  }
  std::cout << std::endl;
}

template <typename T>
void printUsingStringStream()
{
  std::stringstream stream;

  for (T i = 0; i < 16; ++i)
  {
    stream << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i);
  }
  std::cout << stream.str();
 
  std::cout << std::endl;
}

int main()
{
  std::cout << "with cout:" << std::endl;
  printUsingCout<int>();
  printUsingCout<std::uint8_t>();
  printUsingCout<std::uint16_t>();
  printUsingCout<std::uint32_t>();

  std::cout << "with stringstream:" << std::endl;
  printUsingStringStream<int>();
  printUsingStringStream<std::uint8_t>();
  printUsingStringStream<std::uint16_t>();
  printUsingStringStream<std::uint32_t>();
}
