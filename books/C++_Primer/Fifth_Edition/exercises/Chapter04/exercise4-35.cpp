/**
 * TODO: check this
 */

int main()
{
    char cval;    int ival;      unsigned int ui;
    float fval;   double dval;

    // (a) 1. char to int
    //     2. addition of ints
    //     3. truncation of int to char
    cval = 'a' + 3;

    // (b) 1. ival to double
    //     2. multiplication
    //     2. ui to double
    //     3. subtraction
    //     4. double gets truncated to float at assignment time
    fval = ui - ival * 1.0;

    // (c) 1. unsigned integer to float
    //     2. float multiplication
    //     3. result gets converted to double
    //     4. assignment of a double
    dval = ui * fval;

    // (d) 1. ival to float
    //     2. addition of floats
    //     3. result of this addition to double
    //     4. addition of doubles
    //     5. truncation of double to char
    cval = ival + fval + dval;
}
