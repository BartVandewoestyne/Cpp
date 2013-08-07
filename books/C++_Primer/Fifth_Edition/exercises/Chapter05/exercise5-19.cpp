#include <iostream>
#include <string>
using namespace std;

int main()
{
    string answer;
    do {

        cout << "Please enter two strings: ";

        string s1, s2;
        cin >> s1 >> s2;

        if (s1 < s2)
        {
            cout << s1 << " is smaller than " << s2 << endl;
        }
        else if (s2 < s1)
        {
            cout << s2 << " is smaller than " << s1 << endl;
        }
        else
        {
            cout << "Both strings are equal!" << endl;
        }
        cout << "More? Enter yes or no: ";
        cin >> answer;

    } while (!answer.empty() && answer[0] != 'n');

}
