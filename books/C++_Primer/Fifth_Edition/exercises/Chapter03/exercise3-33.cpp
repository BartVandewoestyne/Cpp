#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned scores[11] = {};  // 11 buckets, all value initialized to 0
    //unsigned scores[11];  // if we do not initialize to 0, values are
                            // unreliable.

    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10]; // increment the counter for the current cluster
    }

    for (auto i : scores)  // for each counter in scores
        cout << i << " ";  // print the value of that counter
    cout << endl;
}
