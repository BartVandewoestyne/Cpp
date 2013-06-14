#include <iostream>

int main()
{
    int i;

    // error: lvalue required as left operand of assignment
    //if (42 = i) {};

    // The condition in this if assigns the value 42 to i and then tests the
    // result of the assignment.  Since i is nonzero, the condition will be
    // true.
    if (i = 42) { std::cout << "TRUE" << std::endl; };
}
