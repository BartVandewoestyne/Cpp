#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::string word;
  std::vector<std::string> v;

  std::cout << "Enter words, separated by newlines and followed by "
               "end-of-file (CTRL+z on Windows, CTRL+d on unix)." << std::endl;
  while (std::cin >> word)
  {
    v.push_back(word);
  }

  sort(v.begin(), v.end());

  std::vector<std::string>::const_iterator it;
  for (it = v.begin(); it < v.end(); it++) {
    std::cout << *it << std::endl;
  }

  for (std::vector<std::string>::size_type i = 0; i < v.size(); i++)
  {
    unsigned int count = 1;
    while ( i < v.size() - 1 && v.at(i) == v.at(i+1) )
    {
      count++;
      i++;
    }
    std::cout << v.at(i) << ": " << count << " occurences." << std::endl;
  }

  return 0;
}
