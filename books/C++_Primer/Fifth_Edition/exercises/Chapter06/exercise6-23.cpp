// TODO: 
//  * Make this work for i too.
//  * What about the print1 function?

#include <iostream>
#include <iterator>
using namespace std;

void print1(const int *cp)
{
    if (cp)
        while (*cp != -1)  // assume -1 is end of data
            cout << *cp++;
}

void print2(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print3(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << endl;
    }
}

int main()
{
    int i = 0, j[2] = {0, 1};

    //print1(&i);
    //print1(j);

    //print2(begin(&i), end(&i));
    print2(begin(j), end(j));

    print3(j, end(j) - begin(j));
}
