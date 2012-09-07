/************************************************
 * Pointer demonstration.                       *
 ************************************************/
#include <iostream>

static int data[16];    // Data to be stored
static int n_data = 0;  // Number of items stored

int main()
{
    int *data_ptr;      // Pointer to current item

    // Zero the data array
    for (data_ptr = data+16-1;
         data_ptr >= data;
         --data_ptr)
    {
        *data_ptr = 0;
    }

    // Enter data into the array
    for (n_data = 0; n_data < 16; ++n_data) {
        std::cout <<
            "Enter an item or 0 to end: ";
        std::cin >> data[n_data];

        if (data[n_data] == 0)
            break;
    }

    // Index for summing
    int index;

    // Total of the items in the array
    int total = 0;

    // Add up the items in the array
    for (index = 0; index < n_data; ++index)
        total += data[index];

    // Print the total
    std::cout << "The total is: " <<
        total << std::endl;

    return (0);
}
