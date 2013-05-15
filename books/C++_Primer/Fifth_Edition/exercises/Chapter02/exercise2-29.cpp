int main()
{
    int i = 1;
    const int ic = 2;
    int *p1 = &i;
    int *const p2 = &i;
    const int *const p3 = &ic;

    // (a) OK!
    i = ic;

    // (b) error: invalid conversion from ‘const int*’ to ‘int*’
    //p1 = p3;

    // (c) error: invalid conversion from ‘const int*’ to ‘int*’
    //p1 = &ic;

    // (d) error: assignment of read-only variable ‘p3’
    //p3 = &ic;

    // (e) error: assignment of read-only variable ‘p2’
    //p2 = p1;

    // (f) error: assignment of read-only variable ‘ic’
    //ic = *p3;
}
