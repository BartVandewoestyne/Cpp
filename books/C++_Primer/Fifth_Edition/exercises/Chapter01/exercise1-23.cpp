/*
 * TODO: check if we can do it more elegantly.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item oldItem, newItem;

    int counter = 1;

    std::cin >> newItem;
    oldItem = newItem;
    while (std::cin >> newItem) {

        if ( newItem.isbn() == oldItem.isbn() ) {
            counter++;
        } else {
            std::cout << "Number of transactions for ISBN " << oldItem.isbn()
                      << ": " << counter << std::endl;
            counter = 1;
        }

        oldItem = newItem;

    }
    std::cout << "Number of transactions for ISBN " << oldItem.isbn()
              << ": " << counter << std::endl;
}
