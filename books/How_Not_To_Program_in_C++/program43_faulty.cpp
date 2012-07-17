/************************************************
 * demonstrate the use of derived classes.      *
 ************************************************/
#include <iostream>

/************************************************
 * base -- A sample base class.                 *
 *      Prints various values.                  *
 ************************************************/
class base
{
        // Constructor defaults
        // Destructor defaults
        // Copy constructor defaults
        // Assignment operator defaults
    public:
        // Print a floating point number
        void print_it(
            float value // The value to print
        )
        {
            std::cout <<
                "Base (float=" << value << ")\n";
        }
        // Print an integer value
        void print_it(
            int value   // The value to print
        )
        {
            std::cout <<
                "Base (int=" << value << ")\n";
        }
};

class der : public base
{
        // Constructor defaults
        // Destructor defaults
        // Copy constructor defaults
        // Assignment operator defaults
    public:
        // Print a floating point number
        void print_it(
            float value // The value to print
        )
        {
            std::cout <<
                "Der (float=" << value << ")\n";
        }
};

int main()
{
    der a_var;  // A class to play with

    // Print a value using der::print_it(float)
    a_var.print_it(1.0);

    // Print a value using base::print_it(int)
    a_var.print_it(2);
    return (0);
}
