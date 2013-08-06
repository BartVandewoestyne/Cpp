int main()
{
    int sz = 3;

    // PROBLEM: delta between ix and sz will remain.
    for (int ix = 0; ix != sz; ++ix, ++sz) { /* ... */ }
}
