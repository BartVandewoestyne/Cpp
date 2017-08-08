/*
 * References:
 */

#include <algorithm>
#include <iostream>

class Foo {
public:
  int x;
};

const int NB_ROWS = 2;
const int NB_COLS = 3;

void print(const Foo myArray[NB_ROWS][NB_COLS])  // TODO: check if correct.
{
    for (int i = 0; i < NB_ROWS; ++i)
    {
        for (int j = 0; j < NB_COLS; ++j)
        {
          std::cout << myArray[i][j].x << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Initialize to any value
    {
        Foo y[NB_ROWS][NB_COLS];

        std::for_each(&y[0][0], &y[0][0] + sizeof(y)/sizeof(y[0][0]), [] (Foo& foo) { foo.x = 4; });
        print(y);
    }
}
