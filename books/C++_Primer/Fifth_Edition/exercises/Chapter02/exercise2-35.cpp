// TODO: check this!

int main()
{
    // i is 'const int'
    const int i = 42;

    // j is an 'int' (top-level const in ci is dropped)
    auto j = i;

    // k is 'const int&'
    const auto &k = i;

    // p is 'int*'
    auto *p = &i;

    // j2 is 'const int', k2 is 'const int&'
    const auto j2 = i, &k2 = i;
}
