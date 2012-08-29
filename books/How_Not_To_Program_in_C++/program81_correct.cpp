/************************************************
 * play with a variable size stack class.       *
 ************************************************/

/************************************************
 * stack -- Simple stack class                  *
 *                                              *
 * Member functions:                            *
 *      push -- Push data on to the stack       *
 *      pop -- remove an item from the stack.   *
 ************************************************/
class stack
{
    private:
        int *data;      // The data
        const int size; // The size of the data

        // Number of items in the data
        int count;
    public:
        // Create the stack
        stack(
            // Max size of the stack
            const int _size
        ):size(_size), count(0)
        {
            data = new int[size];
        }
        ~stack(void)
        {
          delete[] data;
        }
    private:
        // No copy constructor
        stack(const stack &);

        // No assignment operator
        stack & operator = (const stack &);
    public:
        // Push something on the stack
        void push(
            // Value to put on stack
            const int value
        )
        {
            data[count] = value;
            ++count;
        }
        // Remove an item from the stack
        int pop(void)
        {
            --count;
            return (data[count]);
        }
};

int main()
{
    stack a_stack(30);

    a_stack.push(1);
    a_stack.push(3);
    a_stack.push(5);
    a_stack.push(7);
    return (0);
}
