#include <string>

// TODO

using std::string;

int main()
{
    const string s = "Keep out!";

    for (auto &c : s)  // TODO: check if the type of c is 'const char&' ???
    {
        /* ... */
    }

    return 0;
}
