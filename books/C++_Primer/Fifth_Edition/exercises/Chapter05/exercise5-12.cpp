#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // initialize counters for each vowel
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

    char ch1;

    while (cin >> ch1) {

        if (ch1 == 'f') {

            char ch2;
            if (cin >> ch2) {

                switch (ch2) {
                    case 'f':
                        ++ffCnt;
                        break;
                    case 'l':
                        ++flCnt;
                        break;
                    case 'i':
                        ++fiCnt;
                        break;
                }

            }

        }

    }

    // print results
    cout << "Number of ff: \t" << ffCnt << '\n'
         << "Number of fl: \t" << flCnt << '\n'
         << "Number of fi: \t" << fiCnt << endl;
}
