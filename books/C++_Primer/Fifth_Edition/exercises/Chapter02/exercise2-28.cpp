// (a) error: uninitialized const ‘cp’
//     => const pointers must be initialized!
//int i, *const cp;

// (b) error: uninitialized const ‘p2’
//     => const pointers must be initialized
//int *p1, *const p2;

// (c) error: uninitialized const ‘ic’
//     => const objects must be initialized
//const int ic, &r = ic;

// (d) error: uninitialized const ‘p3’
//const int *const p3;

// (e) OK!  p is a pointer to an int and may not be used to change the int to
//          which the pointer points.
const int *p;
