/**
 * TODO:
 *   - This compiles with g++ 4.7.2 but gives the error:
 *
 *       terminate called after throwing an instance of 'std::regex_error'
 *         what():  regex_error
 *       Aborted (core dumped)
 */

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string input;
    regex integer("(\\+|-)?[[:digit:]]+");

    // As long as the input is correct ask for another number.
    while (true)
    {
        cout << "Give me an integer!" << endl;
        cin >> input;

        // Exit when the user inputs q.
        if (input == "q")
            break;

        if ( regex_match(input, integer) )
        {
            cout << "Integer." << endl;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
}
