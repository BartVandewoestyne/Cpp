#include <iostream>

int factorial(int val)
{
    //if (val > 1)
    if (val != 0)          // This still works, but one more level of recursion
        return factorial(val-1) * val;
    return 1;
}

int main()
{
    std::cout << factorial(5) << std::endl;
}
