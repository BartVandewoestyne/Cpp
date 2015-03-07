struct X {

    // Error: rem is initialized first with the undefined value for base!
    //X (int i, int j): base(i), rem(base % j) {}

    // Correct version.
    X (int i, int j): rem(i % j), base(i) {}

    int rem, base;
};
