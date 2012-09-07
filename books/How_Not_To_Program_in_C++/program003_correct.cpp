/**************************************************
 * matrix-test -- Test matrix multiply            *
 **************************************************/
#include <stdio.h>

/**************************************************
 * matrix_multiply -- Multiple two matrixes       *
 **************************************************/
static void matrix_multiply(
    int result[3][3], /* The result */
    int matrix1[3][3],/* One multiplicand */
    int matrix2[3][3] /* The other multiplicand */
)
{
    /* Index into the elements of the matrix */
    int row, col, element;

    for(row = 0; row < 3; ++row)
    {
        for(col = 0; col < 3; ++col)
        {
            result[row][col] = 0;
            for(element = 0; element < 3; ++element)
            {
                result[row][col] +=
                    matrix1[row][element]  *
                        matrix2[element][col]; 
             }
        }
    }
}

/************************************************
 * matrix_print -- Output the matrix            *
 ************************************************/
static void matrix_print(
    int matrix[3][3]    /* The matrix to print */
)
{
    int row, col; /* Index into the matrix */

    for (row = 0; row < 3; ++row)
    {
          for (col = 0; col < 3; ++col)
          {
             printf("%d\t", matrix[row][col]);
          }
          printf("\n");
    }
}

int main(void)
{
    /* One matrix for multiplication */
    int matrix_a[3][3] = {
        {45, 82, 26},
        {32, 11, 13},
        {89, 81, 25}
    };
    /* Another matrix for multiplication */
    int matrix_b[3][3] = {
        {32, 43, 50},
        {33, 40, 52},
        {20, 12, 32}
    };
    /* Place to put result */
    int result[3][3];

    matrix_multiply(result, matrix_a, matrix_b);
    matrix_print(result);
    return (0);
}
