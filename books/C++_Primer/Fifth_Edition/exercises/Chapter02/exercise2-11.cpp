// (a) An extern that has an initializer is a definition.
//     Due to the initializer, the extern is overridden.  This statement also
//     results in a warning.
extern int ix = 1024;

// (b) This is a definition because iy is declared and defined (because storage
//     is allocated).
int iy;

// (c) This is a declaration, because iz is not defined (no storage is
//     allocated).
extern int iz;
