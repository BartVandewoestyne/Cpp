/*
 * TODO: check if we can do it more elegantly.
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item newItem;

    if (std::cin >> newItem) {

        int counter = 1;

        Sales_item oldItem = newItem;

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

    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
}
