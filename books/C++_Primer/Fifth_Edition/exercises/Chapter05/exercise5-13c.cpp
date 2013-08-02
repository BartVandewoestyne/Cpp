int get_num()
{
    return 1;
}

int main()
{

    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        //case 1, 3, 5, 7, 9:                     // WRONG
        case 1: case 3: case 5: case 7: case 9:   // FIX
            //oddcnt++;  // WRONG
            oddCnt++;    // FIX
            break;
        //case 2, 4, 6, 8, 10:                    // WRONG
        case 2: case 4: case 6: case 8: case 10:  // FIX
            //evencnt++;  // WRONG
            evenCnt++;    // FIX
            break;
        default:       // It is also better to specify a default label, see top
            break;     // of page 182.
    }

}
