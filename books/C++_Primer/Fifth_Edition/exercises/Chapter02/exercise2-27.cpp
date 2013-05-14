// (a) ERROR: invalid initialization of non-const reference of type ‘int&’
//            from an rvalue of type ‘int’
//     => non-const reference to a const object???
//int i = -1, &r = 0;

// (b) OK!
//int i2 = 1;
//int *const p2 = &i2;

// (c) OK!
//const int i = -1, &r = 0;

// (d) OK!
//int i2 = 1;
//const int *const p3 = &i2;

// (e) OK!
//int i2 = 1;
//const int *p1 = &i2;

// (f) ERROR 1: ‘const’ qualifiers cannot be applied to ‘const int&’
//     ERROR 2: ‘r2’ declared as reference but not initialized
//const int &const r2;

// (g) OK!
//int i = 1;
//const int i2 = i, &r = i;
