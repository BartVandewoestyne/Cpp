// TODO: finish this!
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
  vector<string> words;
  string w;

  while (w != "Quit")
  {
    cin >> w;
    words.push_back(w);
  }

  //for (int i = 0; i < words.size(); i++)
  //{
  //  cout << words[i] << endl;
  //}

  for (set<string>::const_iterator p = words.begin(); p != words.end(); ++p)
  {
    cout << *p << endl;
  }
}
