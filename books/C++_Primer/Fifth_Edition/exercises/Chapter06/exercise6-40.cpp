// (a)
int ff(int a, int b = 0, int c = 0);

// (b) ERROR: if a parameter has a default argument, all the parameters that
// follow it must also have default arguments.
char *init(int ht = 24, int wd, char bckgrnd);
