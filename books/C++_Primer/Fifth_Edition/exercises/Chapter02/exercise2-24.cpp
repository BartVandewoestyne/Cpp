int main()
{
    int i = 42;

    // LEGAL because the type void* is a special pointer type that can hold the
    // address of any object.
    void *p = &i;   

    // ILLEGAL because the types of the pointer and the object to which it
    // points must match (2 exceptions: something that has to do with const and
    // something that has to do with inheritance).
    long *lp = &i;
}
