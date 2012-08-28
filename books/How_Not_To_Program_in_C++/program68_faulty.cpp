/************************************************
 * calc -- Simple 4 function calculator.        *
 *                                              *
 * Usage:                                       *
 *      $ calc                                  *
 *      Enter operator and value: + 5           *
 *                                              *
 * At the end of each operation the accumulated *
 * results are printed.                         *
 ************************************************/
#include <stdio.h>
int main() {
    char oper;  /* Operator for our calculator */
    int  result;/* Current result */
    int value;  /* Value for the operation */

    result = 0;
    while (1)
    {
        char line[100]; // Line from the user
        printf("Enter operator and value:");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c %d", oper, value);

        switch (oper) {
            case '+':
                result += value; break;
            case '-':
                result -= value; break;
            case '*':
                result *= value; break;
            case '/':
                if (value == 0)
                    printf("Divide by 0 error\n");
                else
                    result /= value;
                break;
            case 'q':
                exit (0);
            default:
                printf("Bad operator entered\n"); break;
        }
        printf("Total: %d\n", result);
    }
}
