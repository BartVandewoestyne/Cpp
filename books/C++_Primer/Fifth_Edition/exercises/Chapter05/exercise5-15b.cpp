int main()
{
    int sz = 3;

    // PROBLEM: for-loop has no init-statement.
    //int ix;
    //for (ix != sz; ++ix) { /* ... */ }

    // CORRECTED VERSION
    int ix;
    for (ix = 0; ix != sz; ++ix) { /* ... */ }
}
