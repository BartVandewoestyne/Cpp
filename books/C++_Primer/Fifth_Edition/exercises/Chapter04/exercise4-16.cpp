int* getPtr()
{
    return 0;
}

int main()
{
    int i = 1000;
    int *p;

    // Wrong
    //if (p = getPtr() != 0) {}
    // Corrected
    if ( (p = getPtr() ) != 0) {}

    // Wrong
    //if (i = 1024) {}
    // Corrected
    if (i == 1024) {}
} 
