/**
 * Default parameters.
 */

#include <iostream>

void print(int a=5, int b=10)
{
    std::cout << "a = " << a << ", b = " << b << std::endl;
}
 
int main()
{
    print(3, 4); // override default value for a and b
    print(1);    // b will use default value of 10
    print();     // a and b will use their default values
}
