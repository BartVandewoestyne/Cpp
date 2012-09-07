/************************************************
 * stack_test -- Test the use of the classes    *
 *      stack and safe_stack.                   *
 ************************************************/
#include <iostream>
#include <cstdlib>

// The largest stack we can use
// (private to class stack and safe_stack)
const int STACK_MAX = 100;
/************************************************
 * stack -- Class to provide a classic stack.   *
 *                                              *
 * Member functions:                            *
 *      push -- Push data on to the stack.      *
 *      pop -- Return the top item from the     *
 *              stack.                          *
 *                                              *
 * Warning: There are no checks to make sure    *
 *      that stack limits are not exceeded.     *
 ************************************************/
class stack {
    protected:
        int count; // Number of items in the stack
        int *data; // The stack data
    public:
        // Initialize the stack
        stack(void): count(0)
        {
            data = new int[STACK_MAX];
        }
        // Destructor
        virtual ~stack(void) {
            delete data;
            data = NULL;
        }
    private:
        // No copy constructor
        stack(const stack &);

        // No assignment operator
        stack & operator = (const stack &);
    public:
        // Push an item on the stack
        void push(
            const int item       // Item to push
        ) {
            data[count] = item;
            ++count;
        }
        // Remove the an item from the stack
        int pop(void) {
            --count;
            return (data[count]);
        }

        // Function to count things in
        // an array of stacks
        friend void stack_counter(
            stack stack_array[],
            const int n_stacks
        );
};

/***********************************************
 * safe_stack -- Like stack, but checks for    *
 *      errors.                                *
 *                                             *
 * Member functions: push and pop              *
 *              (just like stack)              *
 ***********************************************/
class safe_stack : public stack {
    public:
        const int max;  // Limit of the stack
    public:
        safe_stack(void): max(STACK_MAX) {};
        // Destructor defaults
    private:
        // No copy constructor
        safe_stack(const safe_stack &);

        // No assignment operator
        safe_stack & operator =
            (const safe_stack &);
    public:
        // Push an item on the stack
        void push(
            // Data to push on the stack
            const int data
        ) {
            if (count >= (STACK_MAX-1)) {
                std::cout << "Stack push error\n";
                exit (8);
            }
            stack::push(data);
        }
        // Pop an item off the stack
        int pop(void) {
            if (count <= 0) {
                std::cout << "Stack pop error\n";
                exit (8);
            }
            return (stack::pop());
        }
};


/************************************************
 * stack_counter -- Display the count of the    *
 *      number of items in an array of stacks.  *
 ************************************************/
void stack_counter(
    // Array of stacks to check
    stack *stack_array,

    // Number of stacks to check
    const int n_stacks
)
{
    int i;

    for (i = 0; i < n_stacks; ++i)
    {
        std::cout << "Stack " << i << " has " <<
            stack_array[i].count << " elements\n";
    }
}

// A set of very safe stacks for testing
static safe_stack stack_array[5];

int main()
{

    stack_array[0].push(0);

    stack_array[1].push(0);
    stack_array[1].push(1);

    stack_array[2].push(0);
    stack_array[2].push(1);
    stack_array[2].push(2);

    stack_array[3].push(0);
    stack_array[3].push(1);
    stack_array[3].push(2);
    stack_array[3].push(3);

    stack_array[4].push(0);
    stack_array[4].push(1);
    stack_array[4].push(2);
    stack_array[4].push(3);
    stack_array[4].push(4);

    stack_counter(stack_array, 5);
    return (0);
}
