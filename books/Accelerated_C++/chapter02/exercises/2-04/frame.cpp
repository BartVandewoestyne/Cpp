// TODO: maybe this program does not really do what was asked...

#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;
using std::endl;
using std::cout;
using std::string;

int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";

    // read the name
    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting
    const int pad = 4;

    // the number of rows and columns to write
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // write a blank line to separate the output from the input
    cout << endl;

    // write rows rows of output
    // invariant: we have written r rows so far
    string top_bottom_line(cols, '*');
    string empty_line(cols-2, ' ');
    for (int r = 0; r != rows; ++r)
    {
        if (r==0 || r==rows-1) {
            cout << top_bottom_line;
        } else if (r == pad + 1) {
            cout << "*" + string(pad, ' ') + greeting + string(pad, ' ') + "*";
        } else {
            cout << "*" + empty_line + "*";
        }
        cout << endl;
    }

    return 0;
}
