unsigned get_bufCnt()
{
    return 1;
}

int main()
{
    //unsigned ival=512, jval=1024, kval=4096;      // WRONG
    const unsigned ival=512, jval=1024, kval=4096;  // FIXED
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
}
