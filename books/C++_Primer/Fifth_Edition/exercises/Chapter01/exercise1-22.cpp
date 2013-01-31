/*
 * TODO: check if this is what the exercise requests.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum;
    Sales_item item;
    while (std::cin >> item) {
        sum += item;
        std::cout << sum << std::endl;
    }
}
