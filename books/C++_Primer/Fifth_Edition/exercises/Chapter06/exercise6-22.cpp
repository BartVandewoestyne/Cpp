/*
 * References:
 *
 *   [1] http://stackoverflow.com/questions/1826203/swapping-addresses-of-pointers-in-c
 */

#include <iostream>

void swap(int*& a, int*& b)
{
    int* temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 1;
    int y = 2;
    int* px = &x;
    int* py = &y;
    
    std::cout << "*px = " << *px << std::endl;
    std::cout << "*py = " << *py << std::endl;

    swap(px, py);

    std::cout << "*px = " << *px << std::endl;
    std::cout << "*py = " << *py << std::endl;
}
