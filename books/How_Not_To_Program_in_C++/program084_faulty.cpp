#include <iostream>
/************************************************
 * trouble -- A class designed to store a       *
 *      single data item.                       *
 *                                              *
 * Member function:                             *
 *      put -- put something in the class       *
 *      get -- get an item from the class       *
 ************************************************/
class trouble {
    private:
        int data;       // An item to be stored
    public:
        trouble(void) { data = 0; }

        trouble(const trouble &i_trouble) {
            std::cout << "Copy Constructor called\n";
            *this = i_trouble;
        }
        trouble operator = (const trouble &i_trouble) {
            std::cout << "= operator called\n";
            data = i_trouble.data;
            return (*this);
        }
    public:
        // Put an item in the class
        void put(const int value) {
            data = value;
        }
        // Get an item from the class
        int get(void) {
            return (data);
        }
};

int main() {
    trouble first;      // A place to put an item
    first.put(99);

    trouble second(first); // A copy of this space

    std::cout << "Second.get " << second.get() << '\n';

    return (0);
}
