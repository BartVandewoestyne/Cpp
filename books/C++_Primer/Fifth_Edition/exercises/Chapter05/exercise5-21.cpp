// TODO: this isn't quite working as it should yet, but i'm too lazy now to fix
// it :-)

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string current, previous;
    while (true) {

        cin >> current;
        cout << "I just read " << current << endl;

        if ( !isupper(current[0]) )
            continue;

        if (previous == current) {
            cout << "Previous word was same as current word." << endl;
            break;
        }

        //string answer;
        //cout << "More words?  Enter yes or no: ";
        //cin >> answer;
        //if (!answer.empty() && answer[0] == 'n')
        //{
        //    break;
        //}

        previous = current;
    }
}
