#include <string>

using std::string;

bool find(string word)
{
    return false;
}

int main()
{
    string s("Bart");
    string word("Test");

    // (a)

    // iter does not have a value yet, and is already compared with s.end()!!!
    //while (string::iterator iter != s.end()) { /* ... */ }

    string::iterator iter = s.begin();
    while (iter != s.end()) { ++iter; }

    // (b)

    // error: ‘status’ was not declared in this scope
    //while (bool status = find(word)) { /* ... */ }
    //if (!status) { /* ... */ }

    bool status = false;
    while (status = find(word)) { /* ... */ }
    if (!status) { /* ... */ }
}
