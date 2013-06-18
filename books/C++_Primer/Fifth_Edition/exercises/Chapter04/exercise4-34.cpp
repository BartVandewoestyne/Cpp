/**
 * TODO: check this!
 */

int main()
{
    bool   flag;    char            cval;
    short  sval;    unsigned short usval;
    int    ival;    unsigned int   uival;
    long   lval;    unsigned long  ulval;
    float  fval;    double          dval;

    // (a) fval converted to bool
    if (fval) {}

    // (b) 1. ival converted to float
    //     2. do addition
    //     3. result of addition gets converted to double
    dval = fval + ival;

    // (c) 1. cval converted to int
    //     2. multiplication of ints
    //     3. result converted to double
    //     4. addition of doubles
    dval + ival * cval;
}
