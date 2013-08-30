class BigInt {};

// (a) Must be in header file because is inline function.
inline bool eq(const BigInt&, const BigInt&) { }

// (b) Declaration in header file, definition in source file.
void putValues(int *arr, int size);
