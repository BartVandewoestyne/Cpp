int main ()
{
  // unsigned char
  typedef unsigned char UnsignedChar;

  // const unsigned char
  typedef const unsigned char ConstantUnsignedChar1;
  typedef unsigned char const ConstantUnsignedChar2;

  // pointer to integer
  typedef int* IntegerPointer;

  // pointer to pointer to char
  typedef char** PointerPointerChar;

  // pointer to array of char
  // See also http://stackoverflow.com/questions/6037426/c-notation-pointer-to-array-of-chars-string
  typedef char* PointerArrayChar1;
  typedef char (*PointerArrayChar2)[3]; // is also correct???

  // array of 7 pointers to int
  typedef IntegerPointer Array7IntegerPointer1[7];
  typedef int* Array7IntegerPointer2[7]; // is this also correct???

  // pointer to an array of 7 pointers to int
  typedef Array7IntegerPointer1* PointerArray7IntegerPointer1; // NOTE: reference solution has error here!
  typedef int* *PointerArray7IntegerPointer2[7]; // is this also correct???

  // array of 8 arrays of 7 pointers to int
  typedef IntegerPointer Array8Array7IntegerPointer1[8][7];
  typedef int (*Array8Array7IntegerPointer2[7])[][8]; // is this also correct???


  /* Example of usage. */
  char a[3] = "ab";       // 'a' is a char[3]
  PointerArrayChar2 ptr;  // 'ptr' is a ptr to a char[3]
  ptr = &a;
}
