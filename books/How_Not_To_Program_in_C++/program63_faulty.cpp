/************************************************
 * Greetings -- Ask the user for his first      *
 *      name and his last name.                 *
 *      Then issue a greeting.                  *
 ************************************************/
#include <stdio.h>
#include <string.h>
int main()
{
    char first[100];    /* The first name */
    char last[100];     /* The last name */
    char full_name[201];/* The full name */

    /* Get the first name */
    printf("First: ");
    fgets(first, sizeof(first), stdin);

    /* Get the last name */
    printf("Last: ");
    fgets(last, sizeof(last), stdin);

    /* Make    full_name = "<first> <last>" */
    strncpy(full_name, first, strlen(first)-1);
    strcat(full_name, " ");
    strncat(full_name, last, strlen(last)-1);

    /* Greet the user by name */
    printf("Hello %s\n", full_name);
    printf("Thank you for "
            "using Acme Software.\n");
    return (0);
}
