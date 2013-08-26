// TODO: check these!

// a) OK!  In these declarations, the second declaration declares the same
// function as the first.
int calc(int, int);
int calc(const int, const int);

// b) It is an error for two functions to differ only in terms of their return
// types.
int get();
//double get();  ERROR: ambiguity

// c) OK
int *reset(int *);
double *reset(double *);
