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
    for (int (&row)[4] : ia)
    {
        for (int& col: row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    // Ordinary for-loop with subscripts.
    for (size_t row = 0; row < 3; ++row)
    {
        for (size_t col = 0; col < 4; ++col)
        {
            cout << ia[row][col] << " ";
        }
        cout << endl;
    }

    // Ordinary for-loop using pointers.
    for (int (*p)[4] = begin(ia); p != end(ia); ++p)
    {
        for (int* q = begin(*p); q != end(*p); ++q)
        {
            cout << *q << " ";
        }
        cout << endl;
    }
}
