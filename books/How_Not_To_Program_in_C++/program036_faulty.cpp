/************************************************
 * test the data_holder class.                  *
 ************************************************/
#include <iostream>
/************************************************
 * data_holder -- A class to hold a single      *
 *      integer                                 *
 *                                              *
 * Member functions:                            *
 *      get -- Get value                        *
 *                                              *
 * Note: By default the value of the data is 5. *
 *                                              *
 * Warning: More member functions need to be    *
 * added to this to make it useful.             *
 ************************************************/
class data_holder {
    private:
        int data;       // Data to store
    public:
        // Constructor -- Set value to default (5)
        data_holder(void):data(5) {};

        // Destructor defaults
        //
        // Copy constructor
        data_holder(const data_holder &old) {
           *this = old;
        }

        // Assignment operator
        data_holder operator = (
                data_holder old_data_holder) {
            data = old_data_holder.data;
            return (*this);
        }

        // Get the data item
        int get(void)
        {
            return (data);
        }
};

int main() {
    // A data holder
    data_holder var1;

    // Copy of a data holder
    data_holder var2(var1);
    return (0);
}
