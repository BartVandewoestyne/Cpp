int main()
{
    int sz = 3;

    // PROBLEM: ix only exists within the for loop. After the for-loop, ix
    //          is out of scope.
    //for (int ix = 0; ix != sz; ++ix) { /* ... */ }
    //if (ix != sz) {
    //  // ...
    //}

    // CORRECTED VERSION
    int ix;
    for (ix = 0; ix != sz; ++ix) { /* ... */ }
    if (ix != sz) {
      // ...
    }
}
