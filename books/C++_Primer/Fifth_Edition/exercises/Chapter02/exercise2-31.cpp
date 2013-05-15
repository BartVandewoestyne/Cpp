int main()
{
    int i = 1;

    const int v2 = 0;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;

    // Assign 'const int' to 'int&'.
    // => OK!
    r1 = v2;

    // Assign 'const int*' to 'int*'.
    // => error: invalid conversion from ‘const int*’ to ‘int*’
    //p1 = p2;

    // Assign 'int*' to 'const int*'.
    // => OK!
    p2 = p1;

    // Assign 'const int*const' to 'int*'.
    // => error: invalid conversion from ‘const int*’ to ‘int*’
    //p1 = p3;

    // Assign 'const int*const' to 'const int *'.
    // => OK!
    p2 = p3;
}
