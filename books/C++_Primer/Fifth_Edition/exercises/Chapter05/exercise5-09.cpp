#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    char ch;

    while (cin >> ch) {

        // if ch is a vowel, increment the appropriate counter

        if (ch == 'a') {
            ++aCnt;
        }
        if (ch == 'e') {
            ++eCnt;
        }
        if (ch == 'i') {
            ++iCnt;
        }
        if (ch == 'o') {
            ++oCnt;
        }
        if (ch == 'u') {
            ++uCnt;
        }

    }

    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;
}
