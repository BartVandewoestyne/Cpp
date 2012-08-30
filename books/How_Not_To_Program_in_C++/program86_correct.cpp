// TODO: fix this in a clean way.
/************************************************
 * array_test -- Test the use of the array class*
 ************************************************/
#include <iostream>
#include <memory.h>

/************************************************
 * array -- Classic variable length array class.*
 *                                              *
 * Member functions:                            *
 *      operator [] -- Return an item           *
 *              in the array.                   *
 ************************************************/
class array {
    protected:
        // Size of the array
        int size;

        // The array data itself
        int *data;
    public:
        // Constructor.
        // Set the size of the array
        // and create data
        array(const int i_size):
            size(i_size),
            data(new int[size])
        {
            // Clear the data
            memset(data, '\0',
                    size * sizeof(data[0]));
        }
        // Destructor -- Return data to the heap
        virtual ~array(void)
        {
            delete []data;
            data = NULL;
        }
        // Copy constructor.
        // Delete the old data and copy
        array(const array &old_array)
        {
            delete []data;
            data = new int[old_array.size];

            memcpy(data, old_array.data,
                    size * sizeof(data[0]));
        }
        // operator =.
        // Delete the old data and copy
        array & operator = (
                const array &old_array)
        {
            if (this == &old_array)
              return;
            delete []data;
            data = new int[old_array.size];

            memcpy(data, old_array.data,
                    size * sizeof(data[0]));
            return (*this);
        }
    public:
        // Get a reference to an item in the array
        int &operator [](const unsigned int item)
        {
            return data[item];
        }
};

/**********************************************
 * three_more_elements  --                    *
 *      Copy from_array to to_array and       *
 *      put on three more elements.           *
 **********************************************/
void three_more_elements(
    // Original array
    array to_array,

    // New array with modifications
    const array &from_array
)
{
    to_array = from_array;
    to_array[10] = 1;
    to_array[11] = 3;
    to_array[11] = 5;
}
int main()
{
    array an_array(30);  // Simple test array

    an_array[2] = 2;    // Put in an element
    // Put on a few more
    three_more_elements(an_array, an_array);
    return(0);
}
