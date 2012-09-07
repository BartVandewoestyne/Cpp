/************************************************
 * stack_test -- Yet another testing of a       *
 *      stack class.                            *
 ************************************************/
#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;

/************************************************
 * problem -- Class to hold a "problem".   Used *
 *      for exception throwing and catching.    *
 *                                              *
 * Holds a single string which describes the    *
 * error.                                       *
 ************************************************/
class problem
{
    public:
        // The reason for the exception
        const char *what;

        // Constructor.
        // Create stack with messages.
        problem(const char *_what):what(_what){}
};

// Max data we put in a stack
// (private to the stack class)
const int MAX_DATA = 100;
/************************************************
* stack -- Classic stack.                       *
*                                               *
* Member functions:                             *
*      push -- Push an item on the stack.       *
*      pop -- Remove an item from the stack.    *
*                                               *
* Exceptions:                                   *
*      Pushing too much data on a stack or      *
*      removing data from an empty stack        *
*      causes an exception of the "problem"     *
*      class to be thrown.                      *
*                                               *
*       Also if you don't empty a stack         *
*       before you're finished, an exception    *
*       is thrown.                              *
*************************************************/
class stack {
    private:
        // The stack's data
        int data[MAX_DATA];

        // Number of elements
        // currently in the stack
        int count;

    public:
        // Constructor
        stack(void) : count(0) {};

        // Destructor -- Check for non
        ~stack(void)
        {
            // Solution 2: don't throw from destructor.
            //if (count != 0)
            //{
            //    throw(
            //        problem("Stack not empty"));
            //}
        }

        // Push an item on the stack
        void push(
            const int what       // Item to store
        )
        {
            data[count] = what;
            ++count;
        }
        // Remove an item from the stack
        int pop(void)
        {
            if (count == 0)
                throw(
                    problem("Stack underflow"));
        --count;
            return (data[count]);
        }
};

/************************************************
* push_three -- Push three items onto a stack  *
*                                              *
* Exceptions:                                  *
*     If i3 is less than zero, a "problem"     *
*     class exception is thrown.               *
************************************************/
static void push_three(
    const int i1,      // First value to push
    const int i2,      // Second value to push
    const int i3       // Third value to push
)
{
    // Stack on which to push things
    stack a_stack;

    a_stack.push(i1);
    a_stack.push(i2);
    a_stack.push(i3);
    if (i3 < 0)
        throw (problem("Bad data"));
}

// Solution 1: use set_terminate.
// void myterminate () {
//     cerr << "terminate handler called\n";
//     abort();  // forces abnormal termination
// }

int main(void)
{
    //set_terminate(myterminate); // Solution 1
    try {
        push_three(1, 3, -5);
    }
    catch (problem &info) {

        std::cout << "Exception caught: " <<
            info.what << std::endl;

        exit (8);
    }
    catch (...) {
        std::cout <<
            "Caught strange exception " <<
            std::endl;

        exit (9);
    }
    std::cout << "Normal exit" << std::endl;
    return (0);
}
