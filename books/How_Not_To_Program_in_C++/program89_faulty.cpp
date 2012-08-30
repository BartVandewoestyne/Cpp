/************************************************
* Combine strings with a variable length        *
*      string class.                            *
*************************************************/
#include <iostream>
#include <cstring>

/************************************************
 * v_string -- variable length C style string   *
 *                                              *
 * Member functions:                            *
 *      set -- set the value of the string.     *
 *      get -- get the data from the string.    *
 ************************************************/
class v_string
{
    public:
        const char *data;      // The data
        // Default constructor
        v_string(): data(NULL)
        {}
        v_string(const char *const i_data):
            data(strdup(i_data))
        {}
        // Destructor
        ~v_string(void)
        {
            // Note: delete works
            // even if data is NULL
            delete [] data;
            data = NULL;
        }
        // Copy constructor
        v_string(const v_string &old)
        {
            if (data != NULL)
            {
                delete[] data;
                data = NULL;
            }
            data = strdup(old.data);
        }
        // operator =
        v_string & operator = (
                const v_string &old)
        {
            if (this == &old)
                return (*this);

            if (data != NULL)
            {
                delete[] data;
                data = NULL;
            }
            if (old.data == NULL)
            {
                data = NULL;
                return (*this);
            }

            data = strdup(old.data);
            return (*this);
        }
    public:
        // Set a value
        void set(
            // New string value
            const char *const new_data
        )
        {
            if (data != NULL)
            {
                delete [] data;
                data = NULL;
            }
            data = strdup(new_data);

        }
        // Returns the value of the string
        const char * const get(void) const
        {
            return (data);
        }
};
/************************************************
 * operator + -- Combine two  v_strings         *
 ************************************************/
v_string operator + (
        const v_string &first,   // First string
        const v_string &second   // Second string
)
{
    char tmp[100];       // Combined string

    strcpy(tmp, first.get());
    strcat(tmp, second.get());

    // Strings put together
    v_string together(tmp);
    return (together);
}

/************************************************
 * combine -- Combine two strings and           *
 *      print the result.                       *
 ************************************************/
static void combine(
        const v_string &first, // First string
        const v_string &second // Second string
)
{
    v_string together;  // Strings put together
    together = first + second;

    std::cout << "Combination " <<
        together.get() << '\n';
}

int main()
{
    // Strings to combine
    v_string first("First:");
    v_string second("Second");
    v_string third(first);  // I added this line to better illustrate the problem.
    combine(first, second);
    return (0);
}
