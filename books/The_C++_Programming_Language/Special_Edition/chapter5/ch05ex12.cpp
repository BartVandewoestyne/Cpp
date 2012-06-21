#include <iostream>
#include <string>

using namespace std;


int getNbOccurencesString(const string& p, const string& s)
{
  int found;
  int nbFound = 0;
  for (int i = 1; i < s.size(); i++)
  {
    cout << "searching for " << p << " in " << s
         << " at position " << i << "." << endl;
    found = s.compare(i, 2, p);
    if (found == 0) {
      cout << "Found!" << endl;
      nbFound = nbFound + 1;
    }
  }
  return nbFound;
}


int getNbOccurencesChar(const char* p, const char* s)
{
  int found;
  int nbFound = 0;
  string ss = string(s);

  for (int i = 1; i < ss.size(); i++)
  {
    cout << "searching for " << p << " in " << ss
         << " at position " << i << "." << endl;
    found = ss.compare(i, 2, p);
    if (found == 0) {
      cout << "Found!" << endl;
      nbFound = nbFound + 1;
    }
  }
  return nbFound;
}


int main()
{
  string longString = "xabaacbaxabb";
  string shortString = "ab";

  const char* longString2 = "xabaacbaxabb";
  const char* shortString2 = "ab";

  cout << "nbOccurences = "
       << getNbOccurencesString(shortString, longString) << endl;;

  cout << "nbOccurences = "
       << getNbOccurencesChar(shortString2, longString2) << endl;;

}
