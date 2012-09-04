#include <stdlib.h>
#include <iostream>
#include <cstring>

/************************************************
 * info -- A class to hold information.         *
 *                                              *
 * Note:                                        *
 *      Because someone is walking all over our *
 *      memory and destroying our data, we      *
 *      have put two guards at the beginning    *
 *      and end of our class.    If someone     *
 *      messes with us these numbers will       *
 *      be destroyed.                           *
 *                                              *
 * Member functions:                            *
 *      set_data -- Store a string in our data. *
 *      get_data -- Get the data string. *
 *      check_magic -- Check the magic numbers. *
 ************************************************/
// Magic numbers for the start and end of the
// data in the class info
const int START_MAGIC = 0x11223344;
const int END_MAGIC = 0x5567788;
class info
{
    private:
        // Magic protection constant
        const int start_magic;

        // String to be stored
        char data[30];

        // Magic protection constant
        const int end_magic;
    public:
        info(void):
            start_magic(START_MAGIC),
            end_magic(END_MAGIC)
            {}

        // Copy constructor defaults
        // Assignment operator defaults
        // Destructor defaults

        // Store some data in the class
        void set_data(
            // Data to be stored
            const char what[]
        )
        {
            strcpy(data, what);
        }

        // Get the data from the class
        char *get_data(void)
        {
            return (data);
        }

        // Verify that the magic
        // numbers are correct
        void check_magic(void)
        {
            if ((start_magic != START_MAGIC) ||
                (end_magic != END_MAGIC))
            {
                std::cout <<
                    "Info has lost its magic\n";
            }
        }
};

/************************************************
 * new_info -- Create a new version of the      *
 *      info class.                             *
 ************************************************/
struct info *new_info(void)
{
    struct info *result; // Newly created result.

    result = new info;

    return (result);
}
int main()
{
    // An info class to play with
    class info *a_info = new_info();

    a_info->set_data("Data");
    a_info->check_magic();
    return (0);
}
