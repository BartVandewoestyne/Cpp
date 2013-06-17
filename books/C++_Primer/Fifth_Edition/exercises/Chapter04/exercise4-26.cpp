int main()
{
    unsigned long quiz1 = 0;  // we'll use this value as a collection of bits

    // With unsigned int, we might not be able to shift 27 bits to the
    // left because for unsigned int only 16 bits are assured (but you can
    // have more)???
    //unsigned int quiz1 = 0;

    quiz1 |= 1UL << 27;       // indicate student number 27 passed

    quiz1 &= ~(1UL << 27);    // student number 27 failed

    bool status = quiz1 & (1UL << 27);  // how did student number 27 do?
}
