#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> text = {"This is sentence 1.", "This is sentence 2.", "", "New paragraph"};

    // print each line in text up to the first blank line
    for (auto it = text.begin();
         it != text.end() && !it->empty();
         ++it)
    {
        for (auto& c : *it)
        {
            c = toupper(c);
        }
    }

    for (auto it = text.cbegin();
         it != text.cend();
         ++it)
    {
        cout << *it << endl;
    }
}
