#include <iostream>

void printIt(int a[2][3])
//void printIt(int a[][3])  // also seems to work
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void fillIt(int a[2][3])
{
    int idx = 0;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            a[i][j] = idx++;
        }
    }
}

int main()
{
    int a[2][3] = { {1, 1, 1}, {9, 9, 9}};

    printIt(a);

    fillIt(a);

    printIt(a);
}
