int main()
{
    // (a) ERROR: uninitialized const ‘buf’
    //const int buf;

    // (b) OK
    int cnt = 0;

    // (c) OK
    const int sz = cnt;

    // (d) ++cnt is OK, ++sz is ILLEGAL: increment of read-only variable ‘sz’
    //++cnt; ++sz;
}
