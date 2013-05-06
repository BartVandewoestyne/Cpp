int main()
{   
    // Declare i as an int variable and initialize it to 0.
    int i = 0;
    
    // (a) ERROR: 'cannot convert ‘int*’ to ‘double*’ in initialization'
    //double* dp = &i;
    
    // (b) ERROR: 'invalid conversion from ‘int’ to ‘int*’'
    //int *ip = i;
    
    // (c) OK
    int *p = &i;
}
