#include <iostream>

int factorial(int val)
{
    if (val > 1)
        return factorial(val-1) * val;
        //return factorial(val--) * val;   // results in an infinite recursion.
                                           // because we use val and then
                                           // decrement.  So val is used
                                           // instead of val-1.
    return 1;
}

int main()
{
    std::cout << factorial(5) << std::endl;
}
