#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string s;
    cin >> s;

    std::string s_cleaned;
    for (auto c : s)
    {
        // punctuation character: a character that is not a control character, a
        // digit, a letter, or a printable whitespace.
        if (!ispunct(c))
        {
            s_cleaned += c;
        }
    }

    std::cout << s_cleaned << std::endl;
}
