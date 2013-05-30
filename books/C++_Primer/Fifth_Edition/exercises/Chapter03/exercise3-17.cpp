#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    const int MAX_NB_ITEMS = 10;

    string word;
    vector<string> words;

    // Read all words and add them to a vector.
    for (int i = 0; i < MAX_NB_ITEMS; ++i)
    {
        cin >> word;
        words.push_back(word);
    }

    // Change each word to uppercase.
    for (auto& word : words)
    {
        for (auto& c : word)
        {
            c = toupper(c);
        }
    }

    // Print the transformed elements, eight words to a line.
    int counter = 0;
    for ( decltype(words.size()) ix = 0; ix != MAX_NB_ITEMS; ++ix )
    {
        cout << words[ix] << " ";

        counter++;

        if (counter == 8)
        {
            cout << endl;
            counter = 0;
        }
    }

    cout << endl;
}
