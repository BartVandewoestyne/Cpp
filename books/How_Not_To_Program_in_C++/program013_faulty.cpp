/************************************************
 * Billing -- Print out how much we owe         *
 *      customers or they owe us.               *
 ************************************************/
#include <iostream>

// Number of pennies in a dollar
const int DOLLAR = 100;

/************************************************
 * billing -- do the billing.                   *
 *      If the customer owes us money           *
 *              -- output debt.                 *
 *      If we owe more than $100                *
 *              -- output credit.               *
 *      Between $0 and $100 just ignore the     *
 *              account.                        *
 ************************************************/
int billing(
    // Current balance (in cents)
    const int balance
) {
    if (balance < 0)
        if (balance < - (100*DOLLAR))
            std::cout << "Credit " << -balance << std::endl;
    else
        std::cout << "Debt " << balance << std::endl;

    return (0);
}

int main()
{
    /* Test code */
    billing(50);
    billing(-10);
    return (0);
}
