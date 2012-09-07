/*************************************************
 * var_array -- Test variable length array       *
 *      class.                                   *
 *************************************************/
#include <memory.h>

/*************************************************
 * var_array -- Variable length array            *
 *                                               *
 * Member functions:                             *
 *      operator [] -- Return a reference to     *
 *              the item in the array.           *
 *************************************************/

class var_array
{
    private:
        int *data;      // The data
        const int size; // The size of the data
    public:
        // Create the var_array
        var_array(const int _size):
            size(_size)
        {
            data = new int[size];
            memset(data, '\0',
                    size * sizeof(int));
        }
        // Destroy the var_array
        ~var_array(void) {
            delete []data;
        }
    public:
        // Get an item in the array
        int &operator [] (
            // Index into the array
            const unsigned index
        )
        {
            return (data[index]);
        }
};

/************************************************
 * store_it -- Store data in the var_array      *
 ************************************************/
static void store_it(
    // Array to use for storage
    var_array test_array
)
{
    test_array[1] = 1;
    test_array[3] = 3;
    test_array[5] = 5;
    test_array[7] = 7;
}
int main()
{
    var_array test_array(30);

    store_it(test_array);
    return (0);
}
