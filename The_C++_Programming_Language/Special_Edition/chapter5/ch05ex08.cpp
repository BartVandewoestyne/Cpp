/*
 * Compile with:
 *
 *   g++ -S ch05ex08.cpp
 *
 * OR
 *
 *   # create assembler code:
 *   g++ -S -fverbose-asm -g -O2 ch05ex08.cpp -o ch05ex08.s
 *   # create asm interlaced with source lines:
 *   as -alhnd ch05ex08.s > ch05ex08.lst
 *
 * OR
 *
 *   g++ -c -g -Wa,-a,-ad ch05ex08.cpp > ch05ex08.lst
 *
 * TODO: improve this and experiment more.
 */
#include <iostream>

int main ()
{
  char v[] = "abc";

  for (int i = 0; v[i] != 0; i++) {
    std::cout << v[i] << std::endl;
  }

  for (char* p = v; *p != 0; p++) {
    std::cout << *p << std::endl;
  }

}
