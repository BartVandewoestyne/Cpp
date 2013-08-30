// (a) OK: compiler uses constness of argument to decide which function to call.
int calc(int&, int&);
int calc(const int&, const int&);

// (b) OK: compiler uses constness of argument to decide which function to call.
int calc(char*, char*);
int calc(const char*, const char*);

// (c) TODO???  I think this one is also OK.
int calc(char*, char*);
int calc(char* const, char* const);
