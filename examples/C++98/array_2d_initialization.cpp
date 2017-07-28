/*
 * References:
 *   [1] https://stackoverflow.com/questions/3948290/whats-the-safe-way-to-fill-multidimensional-array-using-stdfill
 *   [2] https://stackoverflow.com/questions/3586774/fill-multidimensional-array-elements-with-0s
 *   [4] http://en.cppreference.com/w/cpp/language/aggregate_initialization
 *   [5] C++98 standard ISO/IEC 14882:1998
 */

#include <algorithm>
#include <iostream>

const int NB_ROWS = 2;
const int NB_COLS = 3;

void print(const int myArray[NB_ROWS][NB_COLS])  // TODO: check if correct.
{
    for (int i = 0; i < NB_ROWS; ++i)
    {
        for (int j = 0; j < NB_COLS; ++j)
        {
          std::cout << myArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Initialize to any value.
    {
        int x[NB_ROWS][NB_COLS];

        std::fill(x[0], x[0] + NB_ROWS*NB_COLS, 69);
        print(x);
    }

    // Initializing to zero.
    {
        // See section '8.5.1 Aggregates' in [5]:
        // "An empty initializer-list can be used to initialize any aggregate. If the aggregate is not an
        //  empty class, then each member of the aggregate shall be initialized with a value of the form T() (5.2.3),
        //  where T represents the type of the uninitialized member."
        int x1[NB_ROWS][NB_COLS] = {};
        print(x1);

        int x2[NB_ROWS][NB_COLS] = {{0}};
        print(x2);

        //int x3[NB_ROWS][NB_COLS] {};  // C++11
        //print(x3);
    }
}
