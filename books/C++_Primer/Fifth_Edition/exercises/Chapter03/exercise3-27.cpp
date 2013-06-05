int txt_size()
{
    return 1;
}

int main()
{
    unsigned buf_size = 1024;

    // (a) TODO: this should give an error according to bottom of page 113?
    //     but g++ doesn't complain...?
    int ia1[buf_size];

    // (b) OK
    int ia2[4 * 7 - 14];

    // (c) TODO: Should give error because txt_size() is not constexpr???
    int ia3[txt_size()];

    // (d) error: initializer-string for array of chars is too long
    //char st[11] = "fundamental";
}
