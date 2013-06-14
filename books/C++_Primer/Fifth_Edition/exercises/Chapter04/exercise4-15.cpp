int main()
{
    double dval; int ival; int *pi;

    // Second rightmost assignment is wrong.  One cannot assign the value of a
    // pointer to an int.  This causes the error:
    //
    //   invalid conversion from ‘int*’ to ‘int’
    //
    //dval = ival = pi = 0;

    // Correct version: dereference the pointer.
    dval = ival = *pi = 0;
}
