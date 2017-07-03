/*
 * Program to test how to pass 2D arrays to functions in two cases:
 *   1. When you don't modify the array (see printArray function)
 *   2. When you modify the array (see modifyArray function)
 */

#include <iostream>

class Foo {
public:
    Foo(int value) : x(value) {}
    setValue(int value) { x = value; }
    int getValue() const { return x; }
private:
    int x;
};

void printArray(const Foo foo[2][3])  // TODO: check if correct.
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
          std::cout << foo[i][j].getValue() << " ";
        }
        std::cout << std::endl;
    }
}

void modifyArray(Foo foo[2][3])  // Note that here, we don't pass a reference to the 2D array!
{
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      foo[i][j].setValue(99);
    }
  }
}

int main()
{
    Foo foos[2][3] = { {Foo(1), Foo(2), Foo(3)},
                       {Foo(4), Foo(5), Foo(6)} };

    printArray(foos);
    modifyArray(foos);
    printArray(foos);
}
