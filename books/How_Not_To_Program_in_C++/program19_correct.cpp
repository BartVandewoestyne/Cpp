/************************************************
 * prime -- A very dump program to check to see *
 *       if the numbers 2-9 are prime.          *
 ************************************************/
#include <iostream>

int main()
{
    int i;       // Number we are checking

    for (i = 2; i < 10; ++i) {
        switch(i) {
            case 2:
            case 3:
            case 5:
            case 7:
                std::cout << i << " is prime\n";
                break;
            default:
                std::cout << i <<
                    " is not prime\n";
                break;
        }
    }
    return (0);
}
