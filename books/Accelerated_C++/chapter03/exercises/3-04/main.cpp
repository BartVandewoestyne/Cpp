#include <string>
#include <iostream>

int main()
{
  std::string word;

  std::cout << "Enter words, separated by newlines and followed by "
               "end-of-file (CTRL+z on Windows, CTRL+d on unix." << std::endl;
  std::cin >> word;
  std::string::size_type current_size = word.size();
  std::string::size_type longest_size = current_size;
  std::string::size_type shortest_size = current_size;

  while (std::cin >> word)
  {
    current_size = word.size();
    if (current_size > longest_size)
    {
      longest_size = current_size;
    }
    if (current_size < shortest_size)
    {
      shortest_size = current_size;
    }
  }

  std::cout << "Longest size = " << longest_size << std::endl;
  std::cout << "Shortest size = " << shortest_size << std::endl;

  return 0;
}
