#include <string>

int main ()
{

  /* Dummy stuff that i need to initialize all the things from the exercise. */


  // A character.
  char c = 'a';

  // An array of 10 integers.
  int MyIntArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // An array of character strings (my method... correct?)
  const char* myCharStringArray1[3] = {"Bart", "Jan", "Bert"};

  // An array of character strings (reference solution)
  std::string myCharStringArray2[3] = {"Bart", "Jan", "Bert"};

  // An integer.
  int b = 5;


  /* The real exercise. */

  // A pointer to a character.
  char* myCharPointer = &c;

  // An array of 10 integers.
  int myIntArray[10];

  // A reference to an array of 10 integers.
  int (&myIntArrayRef)[10] = MyIntArray;

  // A pointer to an array of character strings (my method... correct?)
  const char* (*myCharacterStringArrayPointer1)[3] = &myCharStringArray1;

  // A pointer to an array of character strings (reference solution)
  std::string (*myCharacterStringArrayPointer2)[3] = &myCharStringArray2;

  // A pointer to a pointer to a character.
  char** myCharPointerPointer = &myCharPointer;

  // A constant integer (reference solution 1)
  int const myConstantInt1 = 5;

  // A constant integer (reference solution 2, more traditional)
  const int myConstantInt2 = 5;

  // A pointer to a constant integer (my method... correct?)
  const int* myPointerToConstantInt1 = &myConstantInt1;

  // A pointer to a constant integer (reference solution)
  int const* myPointerToConstantInt2 = &myConstantInt2;

  // A constant pointer to an integer.
  int *const myConstantPointerToInt = &b;

}
