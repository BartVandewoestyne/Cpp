/***********************************************
 * Test question:                              *
 *     What does the following program print?  *
 *                                             *
 * Note: The question is designed to tell if   *
 * the student knows the difference between    *
 * automatic and static variables.             *
 ***********************************************/
#include <stdio.h>

/***********************************************
 * first -- Demonstration of automatic         *
 *      variables.                             *
 ***********************************************/
int first(void)
{
    int i = 0; // Demonstration variable

    return (i++);
}

/***********************************************
 * second -- Demonstration of a static         *
 *      variable.                              *
 ***********************************************/
int second(void)
{
    static int i = 0;  // Demonstration variable

    return (i++);
}

int main()
{
    int counter;          // Call counter

    for (counter = 0; counter < 3; counter++)
        printf("First %d\n", first());

    for (counter = 0; counter < 3; counter++)
        printf("Second %d\n", second());

    return (0);
}
