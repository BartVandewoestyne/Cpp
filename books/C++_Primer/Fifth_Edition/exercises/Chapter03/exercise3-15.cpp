#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    const int MAX_NB_STRINGS = 3;

    string word;

    vector<string> v;
     
    for (int i = 0; i != MAX_NB_STRINGS; ++i)
    {
        cin >> word;
        v.push_back(word);
    }

    for (const auto& element : v)
    {
        cout << element << " ";
    }
    cout << std::endl;
}
