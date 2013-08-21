#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// Here, we use reference to const because we do not have to change the string
// to check it for capitals.
bool has_capitals(const string& s)
{
    bool hasCaps = false;

    for (const auto& c : s)
    {
        if (isupper(c))
        {
            hasCaps = true;
        }
    }

    return hasCaps;
}

// Here, we use a reference without const, because we need to change the string.
void to_lowercase(string& s)
{
    for (auto& c : s)
    {
        c = tolower(c);
    }
}

int main()
{
    string s("test");
    std::cout << has_capitals(s) << std::endl;

    to_lowercase(s);
    std::cout << s << std::endl;
}
