/*
 * Simple program to illustrate where template type deduction takes place.
 *
 * References:
 *   [1] https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-2-of-n
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(2);
    v.push_back(9);

    // Template argument deduction takes place here!
    sort(v.begin(), v.end());

    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    cout << "Template argument deduction!" << endl;
}
