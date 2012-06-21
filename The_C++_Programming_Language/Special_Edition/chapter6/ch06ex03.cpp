/*
   Read a sequence of possibly whitespace-separated (name,value) pairs, where
   the name is a single whitespace-separated word and the value is an integer
   or a floating-point value.  Compute and print the sum and mean for each name
   and the sum and mean for all names.  Hint: §6.1.8.
 */
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{

  string name;
  double value;
  std::multimap<string, float> myMap;
  std::multimap<string, float>::iterator pos;
  
  // Read the (name,value) pairs.
  for (int i = 1; i < 3; i++)
  {
    cin >> name;
    cin >> value;
    myMap.insert( pair<string,float>(name,value) );
  }

  // Compute and print the sum and mean for all names.
  double sum = 0;
  for (pos = myMap.begin(); pos != myMap.end(); pos++)
  {
    sum += pos->second;
  }
  cout << "sum = " << sum << ", mean = " << sum/myMap.size() << endl;

  // Compute and print the sum and mean for each name.
  // TODO

}
