/************************************************
 * Test the logic for a simple accounting       *
 *      program.                                *
 ************************************************/
#include <iostream>

int main()
{
    // Amount owed (if any) by the user
    int amount;

    std::cout << "Enter current balance: ";
    std::cin >> amount;

    if (amount = 0)
        std::cout << "You owe nothing\n";
    else
        std::cout << "You owe " << amount << "\n";

    return (0);
}
