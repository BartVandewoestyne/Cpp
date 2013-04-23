// OK
int ival = 1.01;

// error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘double’
//int &rval1 = 1.01;

// OK
int &rval2 = ival;

// error: ‘rval3’ declared as reference but not initialized
//int &rval3;
