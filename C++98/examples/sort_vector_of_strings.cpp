#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    words.push_back("Test");
    words.push_back("test");
    words.push_back("appel");
    words.push_back("banana");

    sort(words.begin(), words.end());

    for (vector<string>::const_iterator it = words.begin();
         it != words.end();
         ++it)
    {
        cout << *it << endl;
    }
}
