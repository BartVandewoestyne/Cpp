#include <iostream>

using namespace std;

int main()
{
  int i;
  int max_length = 5;
  int quest_count = 0;
  char input_line[] = {'a', '?', 'b', '?', 'c'};

  // Method 1: for-loop.
  for (i=0; i < max_length; i++)
  {
    if (input_line[i] == '?')
    {
      cout << "found" << endl;
      quest_count++;
    }
  }

  // Method 2: using while-loop.
  i = 0;
  while (i < max_length)
  {
    if (input_line[i] == '?')
    {
      cout << "found" << endl;
      quest_count++;
    }
    i++;
  }

  // Method 3: using pointer arithmetic.
  for (char* p = input_line; p != input_line+max_length; ++p)
  {
    cout << "*p = " << *p << endl;
    if (*p == '?') {
      cout << "found" << endl;
      quest_count++;
    }
  }

}
