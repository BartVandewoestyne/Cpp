#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // Range for.
    for (const auto& row : ia)
    {
        for (const auto& col: row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    // Ordinary for-loop with subscripts.
    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 4; ++col)
        {
            cout << ia[row][col] << " ";
        }
        cout << endl;
    }

    // Ordinary for-loop using pointers.
    for (auto p = begin(ia); p != end(ia); ++p)
    {
        for (auto q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
}
