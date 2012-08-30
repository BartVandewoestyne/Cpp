/************************************************
 * test the variable length queue class.        *
 ************************************************/
#include <iostream>

/************************************************
 * queue -- Variable length queue class.        *
 *                                              *
 * Member functions:                            *
 *      queue(size) -- Create a queue that can  *
 *              hold up to size elements.       *
 *                                              *
 *      get -- Return an item from the queue.   *
 *              (Elements are gotten in First   *
 *              In First Out (FIFO) order.)     *
 *      put -- Add an item to the queue.        *
 *                                              *
 * WARNING: No safety check is made to make     *
 * sure something is in the queue before        *
 * it is removed.                               *
 ************************************************/
class queue
{
    private:
        int *data;        // The data
        int in_index;     // Input index
        int out_index;    // Output index
        int size;         // # items in the queue

        // Copy data from another queue to me.
        void copy_me(
            // Stack to copy from
            const queue &other
        )
        {
            int i;      // Current element

            for (i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }

        // Inc_index -- Increment an
        // index with wrapping
        void inc_index(int &index)
        {
            ++index;
            if (index == size)
            {
                // Wrap
                index = 0;
            }
        }

        // Assignment operator is private, thereby disallowing assignment
        // of one queue to another.
        queue & operator = (const queue &other);

    public:
        // Create a queue of the given size
        queue(const int _size):
            in_index(0), out_index(0), size(_size)
        {
            data = new int[size];
        }

        // Destructor
        ~queue(void) {}

        // Copy constructor
        queue(const queue &other):
            in_index(other.in_index),
            out_index(other.out_index),
            size(other.size)
        {
            data = new int[size];
            copy_me(other);
        }
    public:
        // Put an item on the queue
        void put(
             // Value to Put on the queue
             const int value
        )
        {
             data[in_index] = value;
            inc_index(in_index);
        }
        // Return first element from the queue
        int get(void)
        {
            // Value to return
            int value = data[out_index];

            inc_index(out_index);
            return (value);
        }
};

int main()
{
    // Queue to play around with
    queue a_queue(30);

    // Loop counter for playing with the queue
    int i;

    for (i = 0; i < 30; ++i)
        a_queue.put(i);

    // Create a new queue, same as the current one
    queue save_queue(20);
    //save_queue = a_queue; // not possible anymore.

    std::cout << "Value is " <<
        a_queue.get() << std::endl;

    std::cout << "Value is " <<
        a_queue.get() << std::endl;

    std::cout << "Value is " <<
        a_queue.get() << std::endl;

    std::cout << "Value is " <<
        a_queue.get() << std::endl;

    return (0);
}
