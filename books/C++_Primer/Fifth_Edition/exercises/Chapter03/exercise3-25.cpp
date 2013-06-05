/*
 * Remark: stop this program with EOF input (CTRL+D in Linux)
 *         or feed it a file with scores.
 */
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores1(11, 0);
    vector<unsigned> scores2(11, 0);
    auto beg = scores2.begin();
    auto end = scores2.end();

    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            // with iterators
            auto pos = beg + grade/10;
            *pos += 1;

            // using indices (for checking)
            ++scores1[grade/10];
        }
    }

    for (auto s : scores1)
    {
        cout << s << " ";
    }
    cout << endl;

    for (auto s : scores2)
    {
        cout << s << " ";
    }
    cout << endl;
}
