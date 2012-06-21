/* See also http://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/Type-Attributes.html */

#include <iostream>

struct address {
  char* name;      // "Jim Dandy"
  long int number; // 61
  char* street;    // "South St"
  char* town;      // "New Providence"
  char state[2];   // 'N' 'J'
  long zip;        // 9794
};


int main ()
{
  std::size_t size_of_char = sizeof(char);
  std::size_t size_of_char_pointer = sizeof(char*);
  std::size_t size_of_char_array = sizeof(char[2]);
  std::size_t size_of_long_int = sizeof(long int);
  std::size_t size_of_long = sizeof(long);

  std::cout << "sizeof(char) = " << size_of_char << std::endl;
  std::cout << "sizeof(char*) = " << size_of_char_pointer << std::endl;
  std::cout << "sizeof(char[2]) = " << size_of_char_array << std::endl;
  std::cout << "sizeof(long int) = " << size_of_long_int << std::endl;
  std::cout << "sizeof(long) = " << size_of_long << std::endl;

  /* The two below are not necessarily the same! */
  std::cout << "estimated sizeof(address) = "
    << 3*size_of_char_pointer + size_of_long_int
       + size_of_char_array + size_of_long << std::endl;

  std::cout << "sizeof(address) = " << sizeof(address) << std::endl;
}
