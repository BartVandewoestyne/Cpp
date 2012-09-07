/************************************************
 * Demonstrate how to define and use increment  *
 * operator.                                    *
 ************************************************/
#include <iostream>

/************************************************
 * num -- Class to hold a single number         *
 ************************************************/
class num
{
        // Constructor defaults
        // Destructor defaults
        // Copy Constructor defaults
        // Assignment operator defaults
    public:
        // Value stored in the function
        int value;

        // Increment operator (i++)
        num operator ++(int)
        {
            num copy(*this);  // Copy for return
            value++;

            return (copy);
        }

        // Increment operator (++i)
        num &operator ++(void)
        {
            value++;
            return (*this);
        }
};

int main()
{
    num i;      // A value to play with

    i.value = 1;
    ++i;
    ++i;
    std::cout << "i is " << i.value << std::endl;

    i.value = 1;
    i++;
    i++;
    std::cout << "i is " << i.value << std::endl;
    return (0);
}
